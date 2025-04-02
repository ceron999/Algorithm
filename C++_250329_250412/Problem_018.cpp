/// <summary>
/// 
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
namespace P18
{
	bool solution(vector<int> arr, int target)
	{
		bool answer = false;

		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size() - 1;i++)
		{
			for (int j = i + 1; j < arr.size(); j++)
			{
				if (arr[i] + arr[j] == target)
				{
					answer = true;
					return answer;
				}
				else if (arr[i] + arr[j] > target)
					break;
			}
		}
		return answer;
	}

    void mapping(vector<int>& hash, const vector<int>& arr, int target)
    {
        for (int i = 0; i < arr.size(); i++) {
            // target보다 큰 값은 담지 않음(답이 될 가능성이 없음)       
            if (arr[i] > target) continue;
            //현재 원소의 값을 hash의 인덱스로 활용, 해당 위치의 값을 1로 설정
            hash[arr[i]] = 1;
        }
    }
    bool solution2(vector<int> arr, int target)
    {
        // target+1개의 공간이 있는 hash벡터 선언
        vector<int> hash(target + 1, 0);

        //arr의 원소들 값에 대해서 hash table 생성
        mapping(hash, arr, target);


        for (int i = 0; i < arr.size(); i++)
        {

            // target에서 arr[i]를 뺀 값이 있는지 확인하기 위해 num 선언 
            int num = target - arr[i];

            // arr[i]가 num과 같은 경우는 답이 될수 없음(제약사항에 중복 숫자가 존재하지 않음)
            if (arr[i] == num) continue; //중복되는 숫자가 없는데  특정값이 현재 숫자가 같은 경우

            // 음수는 존재할 수 없으므로 답이 될 수 없음 
            if (num < 0) continue; // 특정값이 0보다 작을경우

            // num이 있다면 합이 target이 되는 변수를 찾은것이므로, true를 반환
            if (hash[num]) return true; // 값을 찾은 경우
        }
        // 두 수의 합이 target이 되는 경우를 찾지 못하면 false 반환    
        return false;

    }

}

int main()
{
	bool result = P18::solution({ 1,2,3,4,8 }, 7);
	
	cout << result << " ";
}
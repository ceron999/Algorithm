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
            // target���� ū ���� ���� ����(���� �� ���ɼ��� ����)       
            if (arr[i] > target) continue;
            //���� ������ ���� hash�� �ε����� Ȱ��, �ش� ��ġ�� ���� 1�� ����
            hash[arr[i]] = 1;
        }
    }
    bool solution2(vector<int> arr, int target)
    {
        // target+1���� ������ �ִ� hash���� ����
        vector<int> hash(target + 1, 0);

        //arr�� ���ҵ� ���� ���ؼ� hash table ����
        mapping(hash, arr, target);


        for (int i = 0; i < arr.size(); i++)
        {

            // target���� arr[i]�� �� ���� �ִ��� Ȯ���ϱ� ���� num ���� 
            int num = target - arr[i];

            // arr[i]�� num�� ���� ���� ���� �ɼ� ����(������׿� �ߺ� ���ڰ� �������� ����)
            if (arr[i] == num) continue; //�ߺ��Ǵ� ���ڰ� ���µ�  Ư������ ���� ���ڰ� ���� ���

            // ������ ������ �� �����Ƿ� ���� �� �� ���� 
            if (num < 0) continue; // Ư������ 0���� �������

            // num�� �ִٸ� ���� target�� �Ǵ� ������ ã�����̹Ƿ�, true�� ��ȯ
            if (hash[num]) return true; // ���� ã�� ���
        }
        // �� ���� ���� target�� �Ǵ� ��츦 ã�� ���ϸ� false ��ȯ    
        return false;

    }

}

int main()
{
	bool result = P18::solution({ 1,2,3,4,8 }, 7);
	
	cout << result << " ";
}
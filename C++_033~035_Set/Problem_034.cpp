/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/1845
/// 폰켓몬
/// 
/// 문제는 쉬웠지만 불필요한 map을 사용
/// 단순히 unordered_set으로 중복 제거만 하고 해당 종류가 얼마나 있는지는 중요하지 않았음
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
namespace P34
{

    int solution(vector<int> nums)
    {
        unordered_map<int, int> ponketmonMap;
        int getSize = nums.size() / 2;
        for (int i : nums)
        {
            ponketmonMap[i]++;
        }


        int answer =  (ponketmonMap.size() > getSize) ? getSize : ponketmonMap.size();
        return answer;
    }
}

//int main()
//{
//    int result = P34::solution({ 3,1,2,3 });
//
//        cout << result << " ";
//}
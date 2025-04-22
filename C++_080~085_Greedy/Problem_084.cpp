/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/138476
/// ±Ö °í¸£±â
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
namespace P84
{
    int solution(int k, vector<int> tangerine) {
        int answer = 0;

        unordered_map<int, int> tangerineMap;

        for (int i = 0; i < tangerine.size(); i++)
        {
            tangerineMap[tangerine[i]]++;
        }

        vector<pair<int, int>> tangerineVec(tangerineMap.begin(), tangerineMap.end());
        sort(tangerineVec.begin(), tangerineVec.end(), [](const pair<int, int>& a, const pair<int, int>& b)
            {
                return a.second > b.second;
            });

        for (auto nowSizeAndCount : tangerineVec)
        {
            if (k > nowSizeAndCount.second)
            {
                k -= nowSizeAndCount.second;
                answer++;
            }
            else
            {
                k = 0;
                answer++;
                break;
            }
        }

        return answer;
    }
}

//int main()
//{
//    vector<int> tangerine  = { 1, 3, 2, 5, 4, 5, 2, 3 };
//    int result = P84::solution(6, tangerine);
//
//        cout << result << " ";
//}
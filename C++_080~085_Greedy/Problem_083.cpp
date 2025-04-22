/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42885
/// 구명보트
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
namespace P83
{
    int solution(vector<int> people, int limit) 
    {
        int answer = 0;
        sort(people.begin(), people.end(), [](const int& a, const int& b)
            {
                return a < b;
            });

        int startWeight = 0;
        int endWeight = people.size() - 1;

        while (startWeight <= endWeight)
        {
            if (people[startWeight] + people[endWeight] <= limit)
            {
                startWeight++;
            }

            endWeight--;

            answer++;
        }

        return answer;
    }
}

//int main()
//{
//    vector<int> people
//        = { 70, 50, 80, 50 };
//    int limit = 100;
//   int result = P83::solution(people, limit);
//
//        cout << result << " ";
//}
/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12982
/// ¿¹»ê
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace P82
{
    int solution(vector<int> d, int budget) 
    {
        int answer = 0;

        sort(d.begin(), d.end(), [](const int& a, const int& b)
            {
                return a < b;
            });

        for (int nowD : d)
        {
            if (nowD < budget)
            {
                budget -= nowD;
                answer++;
            }
            else
                break;
        }

        return answer;
    }
}

//int main()
//{
//    vector<int> d = { 1,3,2,5,4 };
//    int budget = 9;
//    int result = P82::solution(d, budget);
//
//        cout << result << " ";
//}
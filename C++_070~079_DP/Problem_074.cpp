/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12900
/// 2 * n ≈∏¿œ∏µ
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P74
{
    int solution(int n) 
    {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);

        for (int i = 3; i <= n; i++)
        {
            int result = (dp[i - 2] + dp[i - 1]) % 1000000007;
            dp.push_back(result);
        }

        return dp[n];
    }
}

//int main()
//{
//    int result = P74::solution(4);
//
//        cout << result << " ";
//}
/// <summary>
/// 저자 출제
/// LCS 길이 계산
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P70
{
    vector<vector<int>> dp;

    int solution(string str1, string str2)
    {
        dp.resize(str1.size()+1, vector<int>(str2.size()+1, 0));

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[0].size(); j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[str1.size()][str2.size()];
    }
}

//int main()
//{
//    int result = P70::solution("ABCBDAB", "BDCAB");
//
//        cout << result << " ";
//}
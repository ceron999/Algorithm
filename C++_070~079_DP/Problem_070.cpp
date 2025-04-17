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
        int answer = 0;
        dp.resize(str1.size(), vector<int>(str2.size(), 0));



        return answer;
    }
}

int main()
{
    int result = P70::solution("ABCBDAB", "BDCAB");

        cout << result << " ";
}
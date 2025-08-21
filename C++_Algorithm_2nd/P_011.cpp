
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
/// <summary>
/// 1. s에서 연속적인 알파벳을 제거
/// 2. 성공적으로 반환하면 1 아님 0
/// </summary>
namespace p11
{
    
    int solution(string s)
    {
        int answer = -1;

        stack<char> stk;

        for (char ch : s)
        {
            if (!stk.empty() && stk.top() == ch)
            {
                stk.pop();
            }
            else
                stk.push(ch);
        }

        return stk.empty() ? 1 : 0;
    }

}
//int main()
//{
//    string input = "baabaa";
//
//    int i = p11::solution(input);
//
//    cout << i << endl;
//}
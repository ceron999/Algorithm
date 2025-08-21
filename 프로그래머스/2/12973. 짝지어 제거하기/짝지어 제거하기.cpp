#include <iostream>
#include<string>
#include<stack>
using namespace std;

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
/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12973
/// 짝지어 제거하기
/// 
/// s.size가 최대 100,0000 이므로 반드시 O(N)으로 풀어야 한다.
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>

using namespace std;
namespace P11
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
                continue;
            }
            stk.push(ch);
        }

        answer = stk.empty() ? 1 : 0;

        return answer;
    }
}

//int main()
//{
//	cout << P11::solution("baabaa");
//}
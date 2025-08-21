
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

namespace p10
{
    bool IsPair(const char& a, const char& b)
    {
        if ((a == '(' && b == ')') ||
            (a == '{' && b == '}') ||
            (a == '[' && b == ']'))
            return true;
        else
            return false;
    }

    bool IsPairAvailable(string currS, int startIdx)
    {
        stack<char> stack;
        int count = 0;

        while (count < currS.size())
        {
            char nextChar = currS[startIdx];

            if (stack.size() == 0)
            {
                stack.push(nextChar);

            }
            else
            {
                char nowChar = stack.top();
                if (IsPair(nowChar, nextChar))
                {
                    stack.pop();
                }
                else
                {
                    stack.push(nextChar);
                }
            }

            if (startIdx == currS.size() - 1)
                startIdx = 0;
            else
                startIdx++;

            count++;
        }
        if (stack.empty())
            return true;
        else
            return false;
    }

    int solution(string s) {
        int answer = 0;

        if (s.size() % 2 != 0)
            return 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (IsPairAvailable(s, i))
                answer++;
        }

        return answer;
    }

}
//int main()
//{
//    string input = "[](){}";
//
//    int i = p10::solution(input);
//
//        cout << i << endl;
//}
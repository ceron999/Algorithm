/// <summary>
/// 저자 출제
/// 괄호 짝 맞추기
/// </summary>

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>

using namespace std;
namespace P8
{

	bool solution(string s)
	{
		bool answer;

		stack<char> stack;

		// 0. s의 첫 괄호 == )면 false
		if (s[0] == ')') return false;

		for (char c : s)
		{
			if (!stack.empty() && stack.top() == '(' && c == ')')
			{
				stack.pop();
				continue;
			}
			stack.push(c);
		}

		answer = stack.empty();

		return answer;
	}

	//int main()
	//{
	//	cout<<solution("(())()");
	//}


}
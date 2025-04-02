/// <summary>
/// ���� ����
/// ��ȣ ¦ ���߱�
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

		// 0. s�� ù ��ȣ == )�� false
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
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string input;
	while (getline(cin, input))
	{
		if (input[0] == '.') break;

		stack<char> stk;
		for (char c : input)
		{
			if (c == '(' || c == '[') stk.push(c);
			if (c == ')' || c == ']')
			{
				if (stk.size() == 0)
				{
					stk.push(c);
					break;
				}
				else if (stk.top() == '(' && c == ')') stk.pop();
				else if (stk.top() == '[' && c == ']') stk.pop();
				else break;
			}
		}

		cout << (stk.size() == 0 ? "yes\n" : "no\n");
	}
}
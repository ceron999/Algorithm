#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>

using namespace std;

map<char, char> pairs;

int main()
{
	pairs['('] = ')';
	pairs['['] = ']';

	string input;
	while (std::getline(cin, input))
	{
		if (input[0] == '.') continue;

		stack<char> stk;
		for (char c : input)
		{
			if (c == '(' || c == ')' || c == '[' || c == ']')
			{
				if (stk.size() > 0 && pairs[stk.top()] == c) 
					stk.pop();
				else 
					stk.push(c);
			}
		}


		cout << (stk.size() == 0 ? "yes\n" : "no\n");
	}
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;



int main()
{
	int n;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		stack<char> stk;
		string input;
		cin >> input;

		for (char c : input)
		{
			if (stk.size() > 0 && stk.top() == '(' && c == ')') stk.pop();
			else
				stk.push(c);
		}

		cout << ((stk.size() == 0) ? "YES\n" : "NO\n");
	}
}
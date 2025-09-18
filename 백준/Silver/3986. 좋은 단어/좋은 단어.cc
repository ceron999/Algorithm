#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;



int main()
{
	int n, ret =0;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;

		stack<char> stk;
		for (char c : s)
		{
			if (stk.size() > 0 && stk.top() == c) stk.pop();
			else
				stk.push(c);
		}

		if (stk.size() == 0) ret++;
	}
	cout << ret;
}
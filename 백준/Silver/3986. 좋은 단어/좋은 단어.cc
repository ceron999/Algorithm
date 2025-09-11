#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

int n, cnt = 0;
string word;
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> word;

		stack<char> stk;
		for (char c : word)
		{
			if (stk.size() != 0 && stk.top() == c)
			{
				stk.pop();
			}
			else
				stk.push(c);
		}

		if (stk.size() == 0)
			cnt++;
	}
	cout << cnt;
	return 0;
}
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int n, p[1000004], dp[1000004];

int main()
{
	fill(&dp[0], &dp[0] + 1000004, -1);
	stack<int> stk;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];

		while (stk.size() > 0 && p[stk.top()] < p[i])
		{
			dp[stk.top()] = p[i];
			stk.pop();
		}
		stk.push(i);
	}
	for (int i = 0; i < n;i++) cout << dp[i] << " ";
}

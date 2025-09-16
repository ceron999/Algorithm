#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int n;
int p[1000004];
int dp[1000004];

int main()
{
	fill(&dp[0], &dp[0] + 1000004, -1);
	cin >> n;

	stack<int> stk;
	for (int i = 1; i <= n;i++)
	{
		cin >> p[i];

		while (stk.size() > 0 && p[stk.top()] < p[i])
		{
			dp[stk.top()] = p[i];
			stk.pop();
		}
		stk.push(i);
	}

	for (int i = 1; i <= n; i++) cout << dp[i] << " ";
}
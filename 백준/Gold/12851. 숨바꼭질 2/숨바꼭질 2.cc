#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, k, dp[100004];
int cnt = 0;
int main()
{
	cin >> n >> k;

	dp[n] = 0;
	queue<int> q;
	q.push(n);

	if (n == k)
	{
		cout << 0 << "\n";
		cout << 1 << "\n";
		return 0;
	}

	while (q.size())
	{
		int now = q.front(); q.pop();

		for (int i = 0; i < 3; i++)
		{
			int next = now;
			switch (i)
			{
			case 0:
				next += 1;
				break;
			case 1:
				next -= 1;
				break;
			case 2:
				next *= 2;
				break;
			}

			if (next < 0 || next > 100000) continue;
			if (dp[next] != 0 && dp[next] < dp[now] + 1) continue;
			if (next == k)
			{
				if (dp[k] == 0)
				{
					cnt++;
					dp[k] = dp[now] + 1;
				}
				else if(dp[now] + 1 == dp[k])
				{
					cnt++;
				}
				continue;
			}

			dp[next] = dp[now] + 1;
			q.push(next);
		}
	}

	cout << dp[k] << "\n";
	cout << cnt<< "\n";
}
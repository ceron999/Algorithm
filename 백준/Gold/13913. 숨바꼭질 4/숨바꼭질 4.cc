#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, k;
int dp[100004];
int parent[100004];

int main()
{
	fill(&parent[0], &parent[0] + 100004, -1);
	cin >> n >> k;

	dp[n] = 1;

	queue<int> q;
	q.push(n);

	if (n == k)
	{
		cout << 0<< "\n";
		cout << n;
		return 0;
	}

	while (q.size())
	{
		int now = q.front(); q.pop();

		for (int next : {now + 1, now - 1, now * 2})
		{
			if (next < 0 || next > 100000) continue;
			if (dp[next] != 0 && dp[next] < dp[now] + 1) continue;
			if (next == k)
			{
				if (dp[next] == 0 || dp[next] > dp[now] + 1)
				{
					dp[next] = dp[now] + 1;
					parent[next] = now;
					
					q = queue<int>();
					break;
				}
			}

			dp[next] = dp[now] + 1;
			parent[next] = now;

			q.push(next);
		}
	}

	cout << dp[k] - 1 << endl;
	
	int curr = k;
	vector<int> result;
	while (parent[curr] != -1)
	{
		result.push_back(curr);
		curr = parent[curr];
	}
	result.push_back(n);
	
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << " ";
}
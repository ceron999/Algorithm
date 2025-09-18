#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int mn = 987654321;
int n, scv[3];
int dp[64][64][64];

int damage[][3] =
{
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,3,9},
	{1,9,3},
};

struct Hp
{
	int a;
	int b;
	int c;
};

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> scv[i];

	queue<Hp> q;
	Hp first;
	first.a = scv[0];
	first.b = scv[1];
	first.c = scv[2];

	q.push(first);
	dp[scv[0]][scv[1]][scv[2]] = 1;

	while (q.size())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		for (int i = 0; i < 6;i++)
		{
			int na = max(0, a - damage[i][0]);
			int nb = max(0, b - damage[i][1]);
			int nc = max(0, c - damage[i][2]);

			if (dp[na][nb][nc] != 0) continue;
			dp[na][nb][nc] = dp[a][b][c] + 1;

			Hp newHp;
			newHp.a = na;
			newHp.b = nb;
			newHp.c = nc;
			q.push(newHp);
		}
	}

	cout << dp[0][0][0] - 1;
}
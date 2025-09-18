#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
typedef long long ll;

int n,m;
int a[101][101];
int visited[101][101];

int dy[] = {-1,0,1,0};
int dx[] = {-0,1,0,-1};

int main()
{
	cin >> n >> m;

	for (int i = 0;i < n;i++)
	{
		string s;
		cin >> s;
		for (int j = 0;j < m;j++)
		{
			a[i][j] = s[j] - '0';
		}
	}

	visited[0][0] = 1;
	queue<pair<int,int>> q;
	q.push({ 0,0 });

	while (q.size())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0;i < 4;i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
			if (a[ny][nx] == 0) continue;
			if (visited[ny][nx] == 0)
			{
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}

	cout << visited[n - 1][m - 1];

}
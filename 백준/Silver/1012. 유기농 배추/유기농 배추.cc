#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int ret = 0;
int n, m, k, map[51][51];
bool visited[51][51];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] == 0) continue;

		dfs(ny, nx);
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		cin >> m >> n >> k;

		ret = 0;
		fill(&map[0][0], &map[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;

			map[y][x] = 1;
		}

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m; j++)
			{
				if (map[i][j] == 1 && !visited[i][j])
				{
					ret++;
					dfs(i, j);
				}
			}
		}

		cout << ret<< "\n";
	}
}
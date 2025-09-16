#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
char map[51][51];
int visited[51][51];
int n, m, mx = 0;

void bfs(int y, int x)
{
	visited[y][x] = 1;

	queue<pair<int, int>> q;
	q.push({ y, x });

	while (q.size())
	{
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
			if (visited[ny][nx] > 0) continue;
			if (map[ny][nx] == 'W') continue;

			q.push({ ny, nx });
			visited[ny][nx] = visited[now.first][now.second] + 1;

			mx = max(visited[ny][nx], mx);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'L')
			{
				fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

				bfs(i, j);
			}
		}
	}

	cout << mx - 1;
}
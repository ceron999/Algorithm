#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int map[51][51];
bool visited[51][51];
int m, n, k, cnt;

//1 0 0 0 0 0 0 0 0 0
//1 1 0 0 0 0 0 0 0 0
//0 0 0 0 1 0 0 0 0 0
//0 0 0 0 1 0 0 0 0 0
//0 0 1 1 0 1 0 0 0 0
//0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0
//0 0 0 0 1 1 1 0 0 0

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0;i < 4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (map[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;

		dfs(ny, nx);
	}
}

int main()
{
	int t;
	cin >> t;

	while (t != 0)
	{
		t--;
		cnt = 0;

		cin >> m >> n >> k;

		for (int i = 0;i < k;i++)
		{
			int y, x;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
			{
				if (!visited[i][j] && map[i][j] == 1)
				{
					cnt++;
					dfs(i, j);
				}
			}

		cout << cnt << endl;

		// 초기화
		for (int i = 0;i < 51;i++)
		{
			for (int j = 0;j < 51;j++)
			{
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}


	}
}
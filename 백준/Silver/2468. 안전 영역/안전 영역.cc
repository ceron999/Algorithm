#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, rain, map[101][101],maxCnt = 0;
bool visited[101][101];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0;i < 4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny>= n || nx < 0 || nx >= n) continue;
		if (map[ny][nx] <= rain) continue;
		if (visited[ny][nx]) continue;

		dfs(ny, nx);
	}
}

int main()
{
	cin >> n;
	int rainMax = 0;

	for (int i = 0;i < n; i++)
		for (int j = 0;j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > rainMax) rainMax = map[i][j];
		}

	for (rain = 0; rain < rainMax;rain++)
	{
		int cnt = 0;
		fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
		for (int i = 0;i < n; i++)
		{
			for (int j = 0;j < n; j++)
			{
				if (!visited[i][j] && map[i][j] > rain)
				{
					cnt++;
					dfs(i, j);
				}
			}
		}

		if (cnt > maxCnt)
			maxCnt = cnt;
	}

	cout << maxCnt;
}

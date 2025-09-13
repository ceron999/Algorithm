#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int ret = 0;
int n, map[101][101], maxNum = 0;
bool visited[101][101];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void dfs(int y, int x, int rain)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] <= rain) continue;

		dfs(ny, nx, rain);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int rain = 0; rain < 100; rain++)
	{
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		int currSafeCount = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && map[i][j] > rain)
				{
					currSafeCount++;
					dfs(i, j, rain);
				}
			}
		}

		maxNum = max(currSafeCount, maxNum);
	}
	cout << maxNum;
}
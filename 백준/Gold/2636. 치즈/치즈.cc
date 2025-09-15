#include<iostream>
#include<vector>

using namespace std;

int n, m, map[101][101], visited[101][101], removeTime = 0, prevCnt = 0;
bool isEdge[101][101];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void SetEdge(int y, int x)
{
	isEdge[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (isEdge[ny][nx]) continue;
		if (map[ny][nx] == 0)
		{
			SetEdge(ny, nx);
		}
	}
}

int CountCheeze()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m;j++)
		{
			if (map[i][j] == 1)cnt++;
		}
	}

	return cnt;
}

int main()
{
	// input
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m;j++)
		{
			cin >> map[i][j];
		}
	}

	while (true)
	{
		fill(&isEdge[0][0], &isEdge[0][0] + 101 * 101, false);
		SetEdge(0, 0);

		int cheeze = CountCheeze();
		if (cheeze == 0) break;
		prevCnt = cheeze;

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m;x++)
			{
				if (isEdge[y][x])
				{
					for (int i = 0; i < 4; i++)
					{
						int ny = y + dy[i];
						int nx = x + dx[i];

						if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
						if (map[ny][nx] == 1)
						{
							map[ny][nx] = 0;
						}
					}
				}
			}
		}
		removeTime++;
	}

	cout << removeTime << "\n";
	cout << prevCnt << "\n";
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, k;
int map[101][101];
bool visited[101][101];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int dfs(int y, int x)
{
	visited[y][x] = true;
	int ret = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] == 1) continue;

		ret += dfs(ny, nx);
	}
	return ret;
}

int main()
{
	cin >> m >> n >> k;

	for (int i = 0;i < k;i++)
	{
		int xMin, xMax, yMin, yMax;

		cin >> xMin >> yMin >> xMax >> yMax;

		for (int y = yMin;y < yMax; y++)
		{
			for (int x = xMin; x < xMax; x++)
			{
				map[y][x] = 1;
			}
		}
	}

	vector<int> result;
	for (int y = 0;y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (map[y][x] == 0 && !visited[y][x])
			{
				result.push_back(dfs(y, x));
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i : result) cout << i << " ";
}
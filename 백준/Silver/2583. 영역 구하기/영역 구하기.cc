#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int xMin, yMin, xMax, yMax;
int m, n, k, cnt;
int map[101][101];
bool visited[101][101];

void dfs(int y, int x, int& size)
{
	visited[y][x] = true;
	size++;

	for (int i = 0;i < 4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] == 1) continue;

		dfs(ny, nx, size);
	}
}

int main()
{
	cin >> m >> n >> k;
	vector<int> result;
	for (int i = 0;i < k;i++)
	{
		cin >> xMin >> yMin >> xMax >> yMax;

		for (int y = yMin; y < yMax; y++)
			for (int x = xMin; x < xMax; x++)
				map[y][x] = 1;
	}
	
	for (int y = 0;y < m;y++)
	{
		for (int x = 0;x < n;x++)
		{
			if (!visited[y][x] && map[y][x] == 0)
			{
				cnt++;
				int size = 0;

				dfs(y, x, size);
				result.push_back(size);
			}
		}
	}

	sort(result.begin(), result.end());
	
	cout << cnt << endl;
	for (int i : result) cout << i << " ";
}
#include<iostream>
#include<vector>

using namespace std;

int n, m, map[9][9], maxSize = 0;
int test[9][9];
bool visited[9][9];
vector<pair<int, int>> virus;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
// 1. 1을 3개를 둔다.
// 2. dfs를 통해 2를 퍼트린다.
// 3. 0 개수를 확인한다.

void spread(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0;i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
		if (visited[ny][nx])continue;
		if (test[ny][nx] == 1) continue;
		
		test[ny][nx] = 2;
		spread(ny, nx);
	}
}

void installWall(int y, int x, vector<pair<int, int>> v)
{
	if (v.size() == 3)
	{
		fill(&visited[0][0], &visited[0][0] + 9 * 9, false);
		copy(&map[0][0], &map[0][0] + 9 * 9, &test[0][0]);

		for (auto it : virus)
		{
			spread(it.first, it.second);
		}

		int count = 0;
		for (int i = 0; i < n;i++)
			for (int j = 0;j < m;j++)
			{
				if (test[i][j] == 0)
					count++;
			}

		maxSize = max(maxSize, count);
		return;
	}

	for(int i= y; i< n;i++)
		for (int j = 0;j < m;j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				v.push_back({ i,j });
				installWall(i, j,v);
				map[i][j] = 0;
				v.pop_back();
			}
		}
}
int main()
{
	cin >> n >> m;
	
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back({ i,j });
		}
	
	vector<pair<int, int>> v;
	installWall(0,0, v);

	cout << maxSize<< endl;
}
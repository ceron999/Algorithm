#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> virus;
vector<pair<int, int>> blank;

int n, m, map[8][8], clone[8][8], ret = 0;
bool visited[8][8];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0;i < 4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] == 1) continue;

		dfs(ny, nx);
	}
}

int spread()
{
	fill(&visited[0][0], &visited[0][0] + 8 * 8, false);
	for (auto it : virus)
	{
		dfs(it.first, it.second);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0;j < m;j++)
			if (map[i][j] == 0 && !visited[i][j])
				cnt++;

	return cnt;
}

int main()
{
	cin >> n >> m;
	for(int i =0;i<n;i++)
		for (int j = 0; j < m;j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back({ i,j });
			if (map[i][j] == 0) blank.push_back({ i,j });
		}

	for (int i = 0;i < blank.size();i++)
	{
		for (int j = i + 1; j < blank.size(); j++)
		{
			for (int k = j + 1; k < blank.size(); k++)
			{
				map[blank[i].first][blank[i].second] = 1;
				map[blank[j].first][blank[j].second] = 1;
				map[blank[k].first][blank[k].second] = 1;

				ret = max(ret, spread());

				map[blank[i].first][blank[i].second] = 0;
				map[blank[j].first][blank[j].second] = 0;
				map[blank[k].first][blank[k].second] = 0;
			}
		}
	}

	cout << ret;
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> Pair;

int n, m;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int map[101][101];
int visited[101][101];

void bfs()
{
	visited[0][0] = 1;

	queue<Pair> q;
	q.push({ 0,0 });

	while (q.size() != 0)
	{
		Pair now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >=m) continue;
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx] != 0) continue;

			visited[ny][nx] = visited[now.first][now.second] + 1;
			q.push({ ny, nx });
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0;i < n;i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m;j++)
		{
			map[i][j] = (input[j] - '0');
		}
	}

	bfs();

	cout << visited[n - 1][m - 1];
}
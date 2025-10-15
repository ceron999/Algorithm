#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n, m, x, y, x2, y2, cnt = 1;
queue<pair<int, int>> q;
char a[301][301];
int visited[301][301];
bool visited_bool[301][301];
string input;

int dy[] = { -1, 0, 1 ,0 };
int dx[] = { 0, 1, 0 ,-1 };

bool search(int y, int x)
{
	bool flag = false;

	if (a[y][x] == '1' || a[y][x] == '#')
	{
		q.push(make_pair(y, x));
		//cout << y << " " << x << endl;
		return true;
	}

	if (a[y][x] == '0' || a[y][x] == '*')
	{
		for (int i = 0;i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny <= 0 || ny > n || nx <= 0 || nx > m) continue;
			if (visited_bool[ny][nx]) continue;

			visited_bool[ny][nx] = true;
			if (search(ny, nx)) flag = true;
		}
	}

	return flag;
}

int main()
{
	cin >> n >> m >> y >> x >> y2 >> x2;
	visited[y][x] = 1;

	for (int i = 0;i < n;i++)
	{
		cin >> input;
		for (int j = 0;j < input.size();j++)
		{
			a[i+1][j+1] = input[j];
		}
	}

	pair<int, int> start = make_pair(y, x);

	while (search(y, x))
	{
		fill(&visited_bool[0][0], &visited_bool[0][0] + 301 * 301, false);

		while (q.size())
		{
			auto curr = q.front(); q.pop();
			visited[curr.first][curr.second] = cnt;
			a[curr.first][curr.second] = '0';
		}
		cnt++;
	}

	cout << visited[y2][x2];
}
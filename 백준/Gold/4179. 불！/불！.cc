#include<iostream>
#include<vector>
#include<tuple>
#include<queue>

using namespace std;

int n, m;
pair<int, int> start;
char a[1004][1004];
int dist[1004][1004];
int fireDist[1004][1004];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int main()
{
	fill(&fireDist[0][0], &fireDist[0][0] + 1004 * 1004, -1);
	fill(&dist[0][0], &dist[0][0] + 1004 * 1004, -1);
	queue<pair<int, int>> q1;

	cin >> n>> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = s[j - 1];
			if (s[j - 1] == 'J')
			{
				if (i == 1 || i == n || j == 1 || j == m)
				{
					cout << 1;
					return 0;
				}
				start = { i,j };
			}
			else if (s[j - 1] == 'F') 
			{
				q1.push({ i,j });
				fireDist[i][j] = 1;
			}
		}
	}

	// 불 최단거리 구하기
	while (q1.size())
	{
		int y, x;
		tie(y, x) = q1.front(); q1.pop();

		for (int i = 0;i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || ny >n || nx < 1 || nx > m) continue;
			if (a[ny][nx] == '#' || a[ny][nx] == 'F') continue;
			if (fireDist[ny][nx] == -1 || fireDist[ny][nx] > fireDist[y][x] + 1)
			{
				fireDist[ny][nx] = fireDist[y][x] + 1;
				q1.push({ ny, nx });
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(start);
	dist[start.first][start.second] = 1;
	
	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front(); q.pop();

		for (int i = 0;i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || ny >n || nx < 1 || nx > m) continue;
			if (a[ny][nx] != '#' && dist[ny][nx] == -1 && (fireDist[ny][nx] == -1 || dist[y][x] + 1 < fireDist[ny][nx]))
			{
				dist[ny][nx] = dist[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}

	int minDist = 99999999;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 || i == n || j == 1 || j == m)
			{
				if(dist[i][j] !=  -1)
					minDist = min(dist[i][j], minDist);
			}
		}
	}

	if (minDist == 99999999)
		cout << "IMPOSSIBLE";
	else
		cout << minDist << endl;
}
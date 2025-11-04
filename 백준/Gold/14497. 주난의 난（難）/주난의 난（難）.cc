#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int n, m, ret, X1,Y1,X2,Y2;

char a[301][301];
int visited[301][301];
string s;
queue<int> q;

int main()
{
	cin >> n >> m;
	cin >> Y1 >> X1 >> Y2 >> X2;

	for (int i = 1; i <= n;i++)
	{
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = s[j - 1];
		}
	}

	q.push(1000 * Y1 + X1);
	visited[Y1][X1] = 1;
	int cnt = 0;

	while (a[Y2][X2] != '0')
	{
		cnt++;
		queue<int> temp;
		while (q.size())
		{
			int y = q.front() / 1000;
			int x = q.front() % 1000;
			q.pop();

			for (int i = 0; i < 4;i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny <1 || ny >n || nx < 1 || nx > m || visited[ny][nx]) continue;

				visited[ny][nx] = cnt;
				if (a[ny][nx] != '0')
				{
					a[ny][nx] = '0';
					temp.push(1000 * ny + nx);
				}
				else q.push(1000 * ny + nx);
			}
		}
		q = temp;
	}

	cout << visited[Y2][X2];
}
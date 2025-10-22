#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int visited[30];
char a[21][21];
int R, C, ret = 0;
string s;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void dfs(int y, int x, int cnt)
{
	if(cnt > ret)
	{
		ret = cnt;
	}

	for (int i = 0;i < 4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny<1 || ny>R || nx<1 || nx>C) continue;
		int next = (int)(a[ny][nx] - 'A');

		if (visited[next] == 0)
		{
			visited[next] = 1;
			dfs(ny, nx, cnt + 1);
			visited[next] = 0;
		}
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 1;i <= R; i++)
	{
		cin >> s;
		for (int j = 1; j <= C; j++)
		{
			a[i][j] = s[j - 1];
		}
	}


	visited[(int)(a[1][1] - 'A')] = 1;
	dfs(1, 1, 1);

	cout << ret;
}
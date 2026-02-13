#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

int r, c, k, a[6][6], v[6][6];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int ret = 0;

void go(int y, int x, int depth)
{
	if (depth == k)
	{
		if (y == 0 && x == c - 1)
		{
			ret++;
		}
		return;
	}

	for (int i = 0; i < 4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (v[ny][nx]) continue;

		v[ny][nx] = 1;
		go(ny, nx, depth + 1);
		v[ny][nx] = 0;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;

	char input;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> input;
			if (input == 'T')
			{
				a[i][j] = 1;
				v[i][j] = 1;
			}
		}
	}

	v[r - 1][0] = 1;
	go(r-1, 0, 1);
	cout << ret;
}
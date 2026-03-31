#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <deque>
#include<cstring>

using namespace std;

int r, c, t, ret;
int a[51][51], temp[51][51];

// upper dir
int dy1[] = { 0,-1,0,1 };
int dx1[] = { 1,0,-1,0 };

// lower dir
int dy2[] = { 0,1,0,-1 };
int dx2[] = { 1,0,-1,0 };

pair<int, int> upper;
pair<int, int> lower;

vector<pair<int, int>> v;
deque<int> dq;

void spread()
{
	memset(temp, 0, sizeof(temp));

	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			if (a[i][j] == 0) continue;
			
			int dust = a[i][j] / 5;
			if (dust == 0) continue;
			
			for (int idx = 0; idx < 4; idx++)
			{
				int ny = i + dy1[idx];
				int nx = j + dx1[idx];
				
				if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
				if (a[ny][nx] == -1) continue;

				temp[ny][nx] += dust;
				
				a[i][j] -= dust;
			}
		}
	}

	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			a[i][j] += temp[i][j];
		}
	}
}

void move(pair<int, int> start, int dy[], int dx[])
{
	v.clear();
	dq.clear();

	int starty = start.first;
	int startx = start.second;
	int ny = starty;
	int nx = startx;

	int idx = 0;

	while (true)
	{
		ny += dy[idx % 4];
		nx += dx[idx % 4];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c)
		{
			ny -= dy[idx % 4];
			nx -= dx[idx % 4];
			idx++;
			continue;
		}if (a[ny][nx] == -1) break;

		v.push_back({ ny, nx });
		dq.push_back(a[ny][nx]);
	}

	dq.push_front(0);
	dq.pop_back();


	for (auto it : v)
	{
		//cout << "{ " << it.first << " " << it.second << " " << dq.front() << " }\n";

		int y = it.first;
		int x = it.second;

		a[y][x] = dq.front();
		dq.pop_front();
	}
}

int main()
{
	cin >> r >> c >> t;

	bool isSet = false;
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cin >> a[i][j];

			if (!isSet && a[i][j] == -1)
			{
				isSet = true;
				upper = { i,j };
				lower = { i + 1,j };
			}
		}
	}

	while (t--)
	{
		spread();
		move(upper, dy1,dx1);
		move(lower, dy2,dx2);
	}
	
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			if (a[i][j] != -1) ret += a[i][j];
		}
	}
	cout << ret<< "\n\n";

	/*for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/

}
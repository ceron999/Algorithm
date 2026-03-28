#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <deque>

using namespace std;

int N, K, L, nowTime = 0, a[101][101];
queue<pair<int, char>> q;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

pair<int, int> dir = { 0, 1 };

deque<pair<int, int>> snake;

bool isGameOver = false;

void Move()
{
	int ny = snake.front().first + dir.first;
	int nx = snake.front().second + dir.second;

	if (ny <1 || ny>N || nx < 1 || nx>N)
	{
		isGameOver = true;
		return;
	}
	if (a[ny][nx] == 2)
	{
		isGameOver = true;
		return;
	}

	// 이동
	if (a[ny][nx] == 1)
	{
		snake.push_front({ ny, nx });
		a[ny][nx] = 2;
	}
	else
	{
		snake.push_front({ ny, nx });
		a[ny][nx] = 2;

		a[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}
}

void Rotate(char c)
{
	pair<int, int> newDir;
	if (c == 'L')
	{
		newDir = { dir.second * -1, dir.first };
	}
	else
	{
		newDir = { dir.second, dir.first * -1 };
	}

	dir = newDir;
}

int main()
{
	cin >> N >> K;

	a[1][1] = 2;
	snake.push_front({ 1,1 });
	for (int i = 0;i < K;i++)
	{
		int y, x;
		cin >> y >> x;
		a[y][x] = 1;
	}

	cin >> L;
	for (int i = 0;i < L;i++)
	{
		int t;
		char c;
		cin >> t >> c;
		q.push({ t,c });
	}

	while (true)
	{
		nowTime++;
		Move();
		if (isGameOver) break;

		if (!q.empty() && q.front().first == nowTime)
		{
			Rotate(q.front().second);
			q.pop();
		}
	}
	cout << nowTime;
}

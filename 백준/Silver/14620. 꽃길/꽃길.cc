#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

const int INF = 987654321;
int n, ret = INF;
int a[14][14], visited[14][14];

void go(int depth)
{
	if (depth == 3)
	{
		int sum = 0;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (visited[y][x])
					sum += a[y][x];
			}
		}

		ret = min(ret, sum);
		return;
	}

	for (int y = 1; y < n - 1; y++)
	{
		for (int x = 1; x < n - 1; x++)
		{
			if (visited[y][x]) continue;
			if (visited[y - 1][x] || visited[y + 1][x] || visited[y][x - 1] || visited[y][x + 1])
				continue;

			visited[y][x] = 1;
			visited[y - 1][x] = 1;
			visited[y + 1][x] = 1;
			visited[y][x - 1] = 1;
			visited[y][x + 1] = 1;

			go(depth + 1);

			visited[y][x] = 0;
			visited[y - 1][x] = 0;
			visited[y + 1][x] = 0;
			visited[y][x - 1] = 0;
			visited[y][x + 1] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	go(0);

	cout << ret;
}
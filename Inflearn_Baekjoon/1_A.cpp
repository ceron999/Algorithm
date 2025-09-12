#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, map[65][65];
string input, ret;

void dfs(int y, int x, int size)
{
	if (size == 1)
	{
		ret.push_back(map[y][x]);
	}

	int num = map[x][y];
	if (map[y][x + size - 1] != num ||
		map[y + size - 1][x] != num ||
		map[y + size - 1][x + size - 1] != num)
	{
		ret.push_back
		dfs(y, x, size / 2);
		dfs(y, x + (size / 2), size / 2);
		dfs(y + (size / 2), x, size / 2);
		dfs(y + (size / 2), x + (size / 2), size / 2);
	}
}

int main()
{
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		cin >> input;
		for (int j = 0;j < n;j++)
		{
			map[i][j] = (input[j] - '0');
		}
	}

	dfs(0, 0, n);
	//test
	cout << endl;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
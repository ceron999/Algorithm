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
		ret.push_back(map[y][x] + '0');
		return;
	}

	int num = map[y][x];

	for (int ny = y; ny < y + size; ny++)
	{
		for (int nx = x; nx < x + size; nx++)
		{
			if (map[ny][nx] != num)
			{
				ret.push_back('(');

				dfs(y, x, size / 2);
				dfs(y, x + (size / 2), size / 2);
				dfs(y + (size / 2), x, size / 2);
				dfs(y + (size / 2), x + (size / 2), size / 2);

				ret.push_back(')');
				return;
			}
		}
	};

	ret.push_back(map[y][x] + '0');
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

	cout << ret;
	//test
	/*cout << endl;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/
}
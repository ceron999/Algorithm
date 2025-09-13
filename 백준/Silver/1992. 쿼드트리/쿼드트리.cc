#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
char map[64][64];

string quard(int y, int x, int size)
{
	string ret = "";
	if (size == 1)
	{
		ret.push_back(map[y][x]);
		return ret;
	}

	char c = map[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (c != map[i][j])
			{
				ret += '(';
				ret += quard(y, x, size / 2);
				ret += quard(y, x + size / 2, size / 2);
				ret += quard(y + size / 2, x, size / 2);
				ret += quard(y + size / 2, x + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}

	ret.push_back(c);
	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0;i < n; i++)
	{
		string input;
		cin >> input;

		for (int j = 0; j < n; j++)
		{
			map[i][j] = input[j];
		}
	}

	string ret = quard(0, 0, n);

	cout << ret;
}
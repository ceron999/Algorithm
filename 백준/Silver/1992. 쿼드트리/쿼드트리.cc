#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;
char a[65][65];
string s;

string quard(int y, int x, int size)
{
	string ret = "";
	char start = a[y][x];

	if (size == 1)
	{
		ret += start;
		return ret;
	}

	for(int ny =y; ny<y + size; ny++)
		for (int nx = x; nx < x + size; nx++)
		{
			if (a[ny][nx] != start)
			{
				ret += "(";
				ret += quard(y, x, size / 2);
				ret += quard(y, x + size / 2, size / 2);
				ret += quard(y + size / 2, x, size / 2);
				ret += quard(y + size / 2, x + size / 2, size / 2);
				ret += ")";
				return ret;
			}
		}

	ret += start;
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = s[j];
		}
	}

	string result = quard(0, 0, n);

	cout << result<< "\n\n";
}
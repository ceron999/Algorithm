#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, j, ret = 0, map[11];
int curr = 1;

int main()
{
	cin >> n >> m >> j;

	for (int i = 0;i < j;i++)
	{
		int pos;
		cin >> pos;

		if (pos < curr)
		{
			ret += curr - pos;
			curr = pos;
		}
		else if (pos > curr + m - 1)
		{
			ret += pos - (curr + m - 1);
			curr = pos - m + 1;
		}
	}

	cout << ret;
}
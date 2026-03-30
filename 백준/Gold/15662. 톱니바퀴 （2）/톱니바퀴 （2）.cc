#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <deque>
#include<cstring>

using namespace std;

int visited[1004];
int a[1004][8];
int t, k;
vector<pair<int, int>> vv;

void rotateCogwheel(int num, int dir)
{
	if (num < 0 || num >= t) return;
	if (visited[num]) return;

	visited[num] = true;


	if(num - 1 >= 0 && a[num][6] != a[num - 1][2])
		rotateCogwheel(num - 1, dir * -1);
	if(num + 1 < t && a[num][2] != a[num + 1][6])
		rotateCogwheel(num + 1, dir * -1);

	if(dir == 1)
		rotate(a[num], a[num] + 7, a[num] + 8);
	else
		rotate(a[num], a[num] + 1, a[num] + 8);
}

int main()
{
	cin >> t;
	for (int i = 0;i < t; i++)
	{
		string s;
		cin >> s;
		for (int j = 0;j < 8;j++)
		{
			a[i][j] = s[j] - '0';
		}
	}

	cin >> k;

	for (int i = 0;i < k;i++)
	{
		int num, dir;
		cin >> num >> dir;

		vv.push_back({ --num, dir });
	}

	for (auto it : vv)
	{
		int num = it.first;
		int dir = it.second;

		memset(visited, 0, sizeof(visited));
		rotateCogwheel(num, dir);
	}

	int ret = 0;
	for (int i = 0;i < t;i++)
	{
		if (a[i][0] == 1) ret++;
	}
	cout << ret;
}
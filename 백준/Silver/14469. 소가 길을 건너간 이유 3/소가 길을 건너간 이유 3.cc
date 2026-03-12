#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, a, b, ret;

vector<pair<int, int>> v;

int main()
{
	cin >> n;
	for (int i = 0;i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	for (auto it : v)
	{
		int arriveTIme = it.first;
		int cost = it.second;

		if (ret < arriveTIme)
		{
			ret = arriveTIme + cost;
		}
		else
		{
			ret += cost;
		}
	}

	cout << ret;
}
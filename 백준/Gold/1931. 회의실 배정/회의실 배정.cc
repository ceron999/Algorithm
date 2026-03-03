#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, s, e, ret;
vector<pair<int, int>> v;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> s >> e;
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end(), cmp);

	int curr = -1;
	for (auto it : v)
	{
		if (curr <= it.first)
		{
			ret++;
			curr = it.second;

			//cout << it.first << " " << it.second << "\n";
		}
	}

	cout << ret;
}
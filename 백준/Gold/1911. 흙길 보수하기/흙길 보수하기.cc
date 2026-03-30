#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <deque>
#include<cstring>

using namespace std;

int n, l, s,e, ret, p;
vector<pair<int, int>> v;

int main()
{
	cin >> n >> l;

	for (int i = 0; i < n;i++)
	{
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end());

	int lastNum = v[v.size() - 1].second;
	int idx = 0;

	while (p < lastNum)
	{
		int startNum = v[idx].first;
		int endNum = v[idx].second;

		if (p < startNum) p = startNum;

		if (startNum <= p && p < endNum)
		{
			ret++;
			p += l;
		}
		else if (p >= endNum)
		{
			idx++;
		}
	}

	cout << ret;
}
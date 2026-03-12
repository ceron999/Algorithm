#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, d, c, ret;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		cin >> d >> c;

		v.push_back({ d,c });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n;i++)
	{
		int duration = v[i].first;
		int cnt = v[i].second;
		pq.push(cnt);
		if (pq.size() > duration)
		{
			pq.pop();
		}
	}

	while (pq.size())
	{
		ret += pq.top();
		pq.pop();
	}
	cout << ret;
}

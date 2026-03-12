#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll s, e, cnt[100001], n, a[100001];
ll ret;

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}

	while (e < n)
	{
		if (!cnt[a[e]])
		{
			cnt[a[e]]++;
			e++;
		}
		else
		{
			ret += (e - s);
			cnt[a[s]]--;
			s++;
		}
	}
	ret += (e - s)* (e - s + 1) / 2;

	cout << ret;
}
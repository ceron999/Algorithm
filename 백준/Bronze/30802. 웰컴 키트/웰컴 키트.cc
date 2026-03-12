#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n, t, p;
int a[6];

int main()
{
	cin >> n;

	for (int i = 0; i < 6; i++) cin >> a[i];

	cin >> t >> p;

	int ret1 = 0;
	for (int i = 0; i < 6; i++)
	{
		ret1 += (a[i] + t - 1) / t;
	}

	cout << ret1 << "\n";
	cout << n / p << " " << n % p;
}
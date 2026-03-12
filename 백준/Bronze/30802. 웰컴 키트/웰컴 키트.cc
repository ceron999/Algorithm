#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n, s, m, l, xl, xxl, xxxl, t, p;

int main()
{
	cin >> n;
	cin >> s >> m >> l >> xl >> xxl >> xxxl;
	cin >> t >> p;

	int ret1 = 0;
	if (s % t > 0) ret1 += s / t + 1;
	else ret1 += s / t;
	if (m % t > 0) ret1 += m / t + 1;
	else ret1 += m / t;
	if (l % t > 0) ret1 += l / t + 1;
	else ret1 +=l / t;
	if (xl % t > 0) ret1 += xl / t + 1;
	else ret1 += xl / t;
	if (xxl % t > 0) ret1 += xxl / t + 1;
	else ret1 += xxl / t;
	if (xxxl % t > 0) ret1 += xxxl / t + 1;
	else ret1 += xxxl / t;

	cout << ret1 << "\n";
	cout << n / p << " " << n % p;
}
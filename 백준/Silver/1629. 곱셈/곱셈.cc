#include<iostream>

using namespace std;

typedef long long ll;

ll a, b, c;

ll go(ll a, ll b)
{
	if (b == 1) return a % c;

	ll ret = go(a, b / 2);

	ret = ((ret % c) * (ret % c)) % c;
	if (b % 2)
	{
		ret = (ret * (a % c)) % c;
	}
	return ret;
}

int main()
{

	cin >> a >> b >> c;

	ll result = go(a, b);
	cout << result;
}
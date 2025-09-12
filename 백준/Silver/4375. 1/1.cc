#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
int n;

int main()
{
	while (cin >> n)
	{
		ll num = 1;
		int cnt = 1;
		while (num % n != 0)
		{
			num = (num * 10 + 1) % n;
			cnt++;
		}

		cout << cnt << "\n";
	}

}
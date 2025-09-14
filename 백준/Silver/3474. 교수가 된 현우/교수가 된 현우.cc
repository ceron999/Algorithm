#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int cnt_5 = 0;
		while (n > 1)
		{
			n /= 5;
			cnt_5 += n;
		}

		cout << cnt_5 << "\n";
	}
}
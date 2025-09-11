#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
int n;

int main()
{
	vector<int> result;
	while (cin >> n)
	{
		int cnt = 1;
		ll num = 1;

		while (num % n != 0)
		{
			num = (num * 10 + 1) % n;
			cnt++;
		}
		result.push_back(cnt);
	}

	for (int i : result)
		cout << i << "\n";

}
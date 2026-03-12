#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[104], n, v, ret = 0;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> v;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == v) ret++;
	}
	cout << ret;
}
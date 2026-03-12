#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxAmount;
int n;
int amount, cnt;
int total = 0;

int main()
{
	cin >> maxAmount >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> amount >> cnt;

		total += amount * cnt;
	}

	if (total == maxAmount) cout << "Yes";
	else cout << "No";
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int num;
int a[8];

int main()
{
	for (int i = 0; i < 8; i++)
	{
		cin >> a[i];
	}

	bool isAscending = true;
	bool isDecending = true;

	for (int i = 1; i <= 8; i++)
	{
		if (a[i - 1] == i) continue;
		else
		{
			isAscending = false;
			break;
		}
	}

	for (int i = 1; i <= 8; i++)
	{
		if (a[i - 1] == 9 - i) continue;
		else
		{
			isDecending = false;
			break;
		}
	}


	if (isAscending) cout << "ascending";
	else if (isDecending) cout << "descending";
	else cout << "mixed";
}
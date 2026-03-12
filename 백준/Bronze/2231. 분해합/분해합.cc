#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n;
int a[1000004];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int dest = i;
		int curr = i;
		while (curr > 0)
		{
			dest += curr % 10;
			curr /= 10;
		}

		if (dest > 1000000)break;
		if(a[dest] == 0 || a[dest] > i)
			a[dest] = i;
	}
	cout << a[n];
}
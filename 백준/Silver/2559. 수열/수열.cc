#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

// 
int n, prefix[100004], k, best = -999999999;

int main()
{
	cin >> n >> k;

	for (int i = 1;i <= n;i++)
	{
		int num;
		cin >> num;
		prefix[i] = prefix[i - 1] + num;
	}

	best = prefix[k];
	for (int i = k + 1; i <= n;i++)
	{
		int curr = prefix[i] - prefix[i - k];
		if (best < curr)
		{
			best = curr;
		}
	}
	cout << best;
	return 0;
}
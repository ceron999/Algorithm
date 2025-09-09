#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, k;

int main()
{
	cin >> n >> k;

	vector<int> inputs;
	inputs.resize(n, 0);

	int best = -999999999;
	int curr = 0;

	for (int i = 0; i < n;i++)
	{
		cin >> inputs[i];

		if (i == k - 1)
		{
			curr += inputs[i];
			best = curr;
		}
		else if (i < k)
			curr += inputs[i];
		else
		{
			curr = curr - inputs[i - k] + inputs[i];
			if (best < curr)
				best = curr;
		}
	}

	if (n == k)
		best = curr;

	cout << best;

	return 0;
}
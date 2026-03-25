#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, a[21][21], diff = 987654321;


int getDiff(vector<int>& v1, vector<int>& v2)
{
	int sum1 = 0;
	int sum2 = 0;

	for (int x : v1)
	{
		for (int y : v1)
		{
			sum1 += a[x][y];
		}
	}
	for (int x : v2)
	{
		for (int y : v2)
		{
			sum2 += a[x][y];
		}
	}

	return abs(sum1 - sum2);
}

void go(int curr, vector<int>& v1, vector<int>& v2)
{
	if (curr == n)
	{
		int currDIff = diff;
		currDIff = getDiff(v1, v2);
		if (diff > currDIff) diff = currDIff;
		return;
	}


	if (v1.size() != n / 2)
	{
		v1.push_back(curr);
		go(curr + 1, v1, v2);
		v1.pop_back();
	}

	if (v2.size() != n / 2)
	{
		v2.push_back(curr);
		go(curr + 1, v1, v2);
		v2.pop_back();
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	vector<int> v1;
	vector<int> v2;
	go(0, v1, v2);

	cout << diff;
}
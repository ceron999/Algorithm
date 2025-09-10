#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

// 갑옷 2개의 재로 합이 M이 되면 된다.(M<=10,000,000)
// N(<=15000)개의 재료와 M으로 총 몇개의 갑옷을 만들 수 있는가?
// 배열 1500만개 미만으로

int n, m, nums[15005], result = 0;

int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (nums[i] >= m)
			continue;

		for (int j = i + 1; j < n;j++)
		{
			if (nums[i] + nums[j] == m)
				result++;
		}
	}
	cout << result;
}
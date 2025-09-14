#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> nums;
	int start = 666;
	while (nums.size() <= 10000)
	{
		int curr = start;
		int count_6 =0;
		while (curr > 1)
		{
			if (curr % 10 == 6)count_6++;
			else count_6 = 0;

			curr /= 10;
			if (count_6 == 3)
			{
				nums.push_back(start);
				break;
			}
		}
		start++;
	}

	cout << nums[n - 1];
}
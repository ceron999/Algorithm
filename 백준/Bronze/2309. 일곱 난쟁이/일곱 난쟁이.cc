#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

// 목적 : 9개의 줄에서 7개의 숫자를 골라 100이 되도록 해야함
vector<int> result;
vector<int> input;
int maxSize = 7;

void combi(int start, vector<int>& nums)
{
	if (nums.size() == maxSize)
	{
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum == 100)
		{
			if (result[0] != -1)
				return;

			for (int i = 0; i < 7; i++)
				result[i] = nums[i];
			return;
		}
	}

	for (int i = start + 1; i < input.size(); i++)
	{
		nums.push_back(input[i]);
		combi(start + 1, nums);
		nums.pop_back();
	}
}

int main()
{
	vector<int> nums;
	input.resize(9, 0);
	result.resize(7, -1);

	for (int i = 0; i < 9; i++)
		cin >> input[i];

	sort(input.begin(), input.end());
	combi(-1, nums);

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}
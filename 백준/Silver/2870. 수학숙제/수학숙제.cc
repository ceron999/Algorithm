#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

// 숫자와 알파벳으로 된 글자 n 줄
// 숫자 찾기 + 비 내림차순 +0 제외
// 연속적인 숫자는 하나의 수



int main()
{
	int n;
	string input;

	cin >> n;

	vector<string> nums;
	while (n--)
	{
		cin >> input;

		string numStr;
		for (int i = 0;i < input.size();i++)
		{
			if (input[i] >= 'a' && input[i] <= 'z')
			{
				if (numStr.size() != 0)
				{
					nums.push_back(numStr);
					numStr.clear();
				}
			}
			else
				numStr.push_back(input[i]);
		}

		if (numStr.size() != 0)
		{
			nums.push_back(numStr);
		}
	}

	for (int i=0;i<nums.size();i++)
	{
		int idx = -1;
		for (char c : nums[i])
		{
			if (c == '0') idx++;
			else
				break;
		}

		if (idx == -1) continue;
		if (idx + 1 == nums[i].size()) nums[i] = '0';
		else
			nums[i] = nums[i].substr(idx + 1);
	}

	sort(nums.begin(), nums.end(), [](const auto& a, const auto& b)
		{
			if (a.size() != b.size())
				return a.size() < b.size();
			return a < b;
		});
	for (string i : nums) 
		cout << i << "\n";
}
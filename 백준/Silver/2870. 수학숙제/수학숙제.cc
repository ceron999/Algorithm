#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main()
{
	int n;
	cin >> n;

	vector<string> nums;
	while (n--)
	{
		string input;
		cin >> input;

		string currNum;
		for (char c : input)
		{
			if (c < 'a')
			{
				currNum.push_back(c);
			}
			else
			{
				if (currNum.size() == 0) continue;

				while (currNum.size() > 0 && currNum[0] == '0')
				{
					currNum.erase(currNum.begin());
				}

				if (currNum.size() != 0)
					nums.push_back(currNum);
				else
					nums.push_back("0");
				currNum = "";
			}
		}

		if (currNum.size() == 0) continue;

		while (currNum.size() > 0 && currNum[0] == '0')
		{
			currNum.erase(currNum.begin());
		}
		if (currNum.size() != 0)
			nums.push_back(currNum);
		else
			nums.push_back("0");
	}

	sort(nums.begin(), nums.end(), [](const string& a, const string& b)
		{
			if (a.size() != b.size()) return a.size() < b.size();
			else
				return a < b;
		});
	
	for (string num : nums) cout << num << "\n";
}
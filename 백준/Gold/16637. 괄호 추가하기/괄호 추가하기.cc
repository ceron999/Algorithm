#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int mx = -987654321;
int n;
vector<int> nums;
vector<char> oper;
string s;

int calculate(char inputOp, int a, int b)
{
	if (inputOp == '+') return a + b;
	else if (inputOp == '-') return a - b;
	else if (inputOp == '*') return a * b;
}

void go(int start, int sum)
{
	if(start == nums.size() - 1)
	{
		mx = max(mx, sum);
		return;
	}
	go(start + 1, calculate(oper[start], sum, nums[start + 1]));

	if (start+ 2 <= nums.size() - 1)
	{
		int temp = calculate(oper[start + 1], nums[start + 1], nums[start + 2]);
		go(start + 2, calculate(oper[start], sum, temp));
	}
}

int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		if (s[i] >= '0' && s[i] <= '9') nums.push_back(s[i] - '0');
		else oper.push_back(s[i]);
	}
	go(0, nums[0]);

	cout << mx;
}
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

// 
int n;
string names[104];

bool IsNotCross(string s)
{
	stack<char> stk;

	for (char c : s)
	{
		if (stk.size() != 0 && stk.top() == c)
			stk.pop();
		else
			stk.push(c);
	}
	
	return stk.size() == 0;
}

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> names[i];

	int count = 0;
	for (int i = 0;i < n;i++)
	{
		if (IsNotCross(names[i]))
			count++;
	}

	cout << count;
}
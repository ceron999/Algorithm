#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

// 
string input;
map<char, int> _map;

int main()
{
	cin >> input;

	for (char c : input)
		_map[c]++;

	char oddChar = '-';
	for (auto it : _map)
	{
		if (it.second % 2 != 0)
		{
			if (oddChar != '-')
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			else
				oddChar = it.first;
		}
	}
	
	string front;
	for (auto it : _map)
	{
		for (int i = 0;i < it.second / 2;i++)
			front.push_back(it.first);
	}

	string result = front;
	if(oddChar != '-')
		result.push_back(oddChar);
	reverse(front.begin(), front.end());


	result += front;
	cout << result;
}

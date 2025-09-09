#include<iostream>
#include<unordered_map>

using namespace std;

// 목적 : 9개의 줄에서 7개의 숫자를 골라 100이 되도록 해야함
unordered_map<char, int> charMap;

int main()
{
	char it = 'a';
	while (it != 'z' + 1)
	{
		charMap.insert(make_pair(it, 0));
		it++;
	}

	string input;
	cin >> input;

	for (char c : input)
	{
		charMap[c]++;
	}

	for (char c = 'a'; c <= 'z' ;c++)
	{
		cout << charMap[c] << " ";
	}

	return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

// a -2 b -2 c -2

int testCase;
int n;
string cName, cType;
map<string, vector<string>> clothMap;

int main()
{
	cin >> testCase;

	vector<int> result;
	for (int test = 0; test < testCase;test++)
	{
		cin >> n;
		for (int i = 0;i < n;i++)
		{
			cin >> cName >> cType;
			clothMap[cType].push_back(cName);
		}

		int sum = 1;
		for (auto it = clothMap.begin();it != clothMap.end();++it)
		{
			sum *= (it->second.size() + 1);
		}

		result.push_back(sum - 1);
		clothMap.clear();
	}

	for (int r : result)
		cout << r << "\n";
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

int n,m;

string input;
unordered_map<int, string> map1;
unordered_map<string, int> map2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n;i++)
	{
		cin>> input;
		map1.insert({ i, input });
		map2.insert({ input, i });
	}

	for (int i = 0;i < m;i++)
	{
		cin >> input;

		int parseNum = atoi(input.c_str());
		if (parseNum == 0)
		{
			cout << map2[input] << "\n";
		}
		else
			cout << map1[parseNum] << "\n";
	}
}
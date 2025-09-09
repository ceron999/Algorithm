#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

int N;
vector<string> players;
unordered_map<char, int> initialMap;

int main()
{
	cin >> N;
	players.resize(N, "");
	for (int i = 0; i < N; i++)
	{
		string player;
		cin >> player;

		initialMap[player[0]]++;
	}

	string result;

	for (auto it = initialMap.begin(); it != initialMap.end(); ++it)
	{
		if (it->second >= 5)
			result.push_back(it->first);
	}

	if (result.size() == 0)
		cout << "PREDAJA";
	else
	{
		sort(result.begin(), result.end());
		cout << result;
	}
	return 0;
}
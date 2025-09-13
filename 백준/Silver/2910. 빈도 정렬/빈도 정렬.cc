#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int n, c;
//<key, <최초 등록 위치, 갯수>>
unordered_map<int, pair<int, int>> countMap;

// x가 y보다 빈도수가 높다면 x가 앞, 같다면 먼저 나온것이 앞
bool compare(const int& a, const int& b)
{
	if (countMap[a].second != countMap[b].second)
		return countMap[a].second > countMap[b].second;
	else
		return countMap[a].first < countMap[b].first;
}

int main()
{
	cin >> n >> c;

	vector<int> num;

	for (int i = 0; i < n; i++)
	{
		int curr;
		cin >> curr;
		if (countMap.find(curr) != countMap.end())
			countMap[curr].second++;
		else
		{
			num.push_back(curr);
			countMap[curr] = { i, 1 };
		}
	}

	sort(num.begin(), num.end(), compare);
	for (int  nowNum : num)
	{
		for(int i =0; i< countMap[nowNum].second; i++)
			cout << nowNum << " ";
	}
}
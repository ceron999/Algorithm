#include<iostream>
#include<vector>

using namespace std;

int n, m, mn = 9999;
int map[51][51];
int dist[51][51];

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

void countChickenDist()
{
	int sum = 0;
	for (auto nowHouse : house)
	{
		for (auto nowChicken : chicken)
		{
			if (map[nowChicken.first][nowChicken.second] == 0) continue;

			int nowDist = abs(nowChicken.first - nowHouse.first) + abs(nowChicken.second - nowHouse.second);

			dist[nowHouse.first][nowHouse.second] = min(dist[nowHouse.first][nowHouse.second], nowDist);
		}
		sum += dist[nowHouse.first][nowHouse.second];
		//cout << "y : " << nowHouse.first << " x : " << nowHouse.second << " dist : " << dist[nowHouse.first][nowHouse.second] << endl;
	}

	mn = min(sum, mn);
}

void combi(int start, vector<int>& v)
{
	if (v.size() == chicken.size() - m)
	{
		fill(&dist[0][0], &dist[0][0] + 51 * 51, 9999);

		for (int i : v)
		{
			auto curr = chicken[i];
			map[curr.first][curr.second] = 0;
		}

		countChickenDist();

		for (int i : v)
		{
			auto curr = chicken[i];
			map[curr.first][curr.second] = 1;
		}

		return;
	}

	for (int i = start + 1; i < chicken.size(); i++)
	{
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	for(int i =0;i< n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 1) house.push_back({ i, j });
			if (map[i][j] == 2) chicken.push_back({ i, j });
		}

	vector<int> removeChicken;
	combi(-1, removeChicken);
	cout << mn;
}
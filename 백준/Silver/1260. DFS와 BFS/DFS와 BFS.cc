#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m, start, temp1, temp2;

bool visited1[1004];
bool visited2[1004];

vector<int> v[1004];
vector<int> bfs;
vector<int> dfs;
queue<int> q;

void BFS()
{
	q.push(start);
	bfs.push_back(start);

	visited1[start] = true;

	while (q.size())
	{
		int curr = q.front(); q.pop();

		for (int i = 0; i < v[curr].size(); i++)
		{
			int next = v[curr][i];

			if (visited1[next]) continue;

			q.push(next);
			bfs.push_back(next);
			visited1[next] = true;
		}
	}

	for (auto num : bfs)
	{
		cout << num << " ";
	}
	cout << "\n";
}

void DFS(int here)
{
	if (visited2[here]) return;

	dfs.push_back(here);
	visited2[here] = true;

	for (int i = 0; i < v[here].size(); i++)
	{
		int next = v[here][i];

		if (visited2[next]) continue;

		DFS(next);
	}
}

int main()
{
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		cin >> temp1 >> temp2;

		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
	}

	for (int i = 0; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	DFS(start);
	
	for (auto num : dfs)
	{
		cout << num << " ";
	}
	cout << "\n";

	BFS();
}
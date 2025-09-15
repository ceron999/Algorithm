#include<iostream>
#include<vector>
#include <queue>

using namespace std;

vector<int> adjList[51];
int n;
bool visited[51];

// 0 - 1 2
// 1 - 0 3 4
// 2 - 0
// 3 - 1
// 4 - 1

int main()
{
	cin >> n;

	int root;
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;

		if (parent == -1)
			root = i;
		else
		{
			adjList[i].push_back(parent);
			adjList[parent].push_back(i);
		}
	}

	int eraseNum;
	cin >> eraseNum;
	if (eraseNum == root) 
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < adjList[eraseNum].size(); i++)
	{
		int target = adjList[eraseNum][i];

		for (auto it = adjList[target].begin(); it != adjList[target].end();)
		{
			if (*it == eraseNum)
				it = adjList[target].erase(it);
			else
				++it;
		}
	}
	adjList[eraseNum].clear();

	int cnt = 0;

	queue<int> q;
	q.push(root);
	visited[root] = true;
	while (q.size())
	{
		int node = q.front();
		q.pop();

		int childCnt = 0;
		for (int child : adjList[node])
		{
			if (!visited[child])
			{
				visited[child] = true;
				q.push(child);
				childCnt++;
			}
		}
		if (childCnt == 0) cnt++;
	}

	cout << cnt;
}
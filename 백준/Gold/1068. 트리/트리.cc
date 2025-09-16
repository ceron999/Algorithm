#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int n, d, ret, root;

vector<int> adjList[54];
bool visited[54];

// 0 - 1 2
// 1 - 3 4
// 2 - 
// 3 - 
// 4 - 

void dfs(int here)
{
	visited[here] = true;

	int childCnt = 0;
	for (int i = 0; i < adjList[here].size(); i++)
	{
		int there = adjList[here][i];
		if (visited[there]) continue;
		if (there == d) continue;

		childCnt++;
		dfs(there);
	}

	if (childCnt == 0) ret++;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;
		if (parent == -1)
		{
			root = i;
			continue;
		}
		adjList[parent].push_back(i);
	}
	cin >> d;

	if (root != d)
		dfs(root);
	else
		ret = 0;

	cout << ret;
}
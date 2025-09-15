#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
using namespace std;

int n, m;
int maxDepth = 0;
bool visited[10004];
vector<int> adjList[10004];
vector<int> nodes;

// 1 - 3 
// 2 - 3
// 3 - 4 5
// 4 - 
// 5 - 

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		adjList[b].push_back(a);
	}

	for (int currNode = 1; currNode <= n; currNode++)
	{
		fill(&visited[0], &visited[0] + 10004, false);

		// currNode를 시작으로 하는 연결 시작
		queue<int> q;
		q.push(currNode);
		visited[currNode] = true;

		int length = 0;
		while (q.size())
		{
			int now = q.front();
			q.pop();

			for (int i = 0;i < adjList[now].size(); i++)
			{
				int nextNode = adjList[now][i];
				if (visited[nextNode]) continue;

				length++;
				q.push(nextNode);
				visited[nextNode] = true;
			}
		}

		if (length > maxDepth)
		{
			nodes.clear();
			nodes.push_back(currNode);
			maxDepth = length;
		}
		else if(length == maxDepth)
			nodes.push_back(currNode);
	}

	sort(nodes.begin(), nodes.end());
	for (int n : nodes) cout << n << " ";
}
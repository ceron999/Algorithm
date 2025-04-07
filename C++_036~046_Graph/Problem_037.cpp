/// <summary>
/// ���� ����
/// BFS ��ȸ
/// 
/// BFS�� �������� ���̵��� �־���
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
namespace P37
{
	unordered_map<int, vector<int>> adjList;
	unordered_set<int> visited;
	vector<int> result;
	queue<int> resultQueue;

	void BFS(int node)
	{
		if (resultQueue.size() == 0)
		{
			return;
		}

		for (int neighbor : adjList[node])
		{
			if (visited.find(neighbor) == visited.end())
			{
				visited.insert(neighbor);
				resultQueue.push(neighbor);
			}
		}

		resultQueue.pop();
		result.push_back(node);

		if (resultQueue.empty()) return;
		BFS(resultQueue.front());
	}

	vector<int> solution(vector<pair<int, int>> graph, int start)
	{
		for (auto& pair : graph)
		{
			adjList[pair.first].push_back(pair.second);
		}

		resultQueue.push(start);
		BFS(start);

		return result;
	}
	// ���� bfs
	void bfs(int start) {
		unordered_set<int> visited;
		queue<int> q;

		//  ���� ��� �湮
		q.push(start);
		visited.insert(start);
		result.push_back(start);

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			// ���� ���� ������ ��� �� ���� �湮���� �ʴ� ��� �湮
			for (int neighbor : adjList[node]) {
				if (visited.find(neighbor) == visited.end()) {
					q.push(neighbor);
					visited.insert(neighbor);
					result.push_back(neighbor);
				}
			}
		}
	}
}

//int main()
//{
//    vector<int> result2 = P37::solution({	{1,2},{1,3},{2,4},{2,5},{3,6},
//											{3,7},{4,8},{5,8},{6,9},{7,9}}, 1);
//
//    for(int i : result2)
//        cout << i << " ";
//}
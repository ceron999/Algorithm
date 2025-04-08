/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/43162
/// 네트워크
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
namespace P42
{
    vector<int> set;
    unordered_map<int, vector<int>> adjList;
    vector<int> setRank;

    int find(int com)
    {
        if (set[com] == com)
            return com;

        set[com] = find(set[com]);

        return set[com];
    }

    void unionSet(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot != yRoot)
        {
            if (setRank[xRoot] < setRank[yRoot])
            {
                set[xRoot] = yRoot;
            }
            else if (setRank[xRoot] > setRank[yRoot])
            {
                set[yRoot] = xRoot;
            }
            else
            {
                set[xRoot] = yRoot;
                setRank[xRoot]++;
            }
        }
    }

    int solution(int n, vector<vector<int>> computers)
    {
        int answer = 0;
        setRank.resize(n, 0);
        unordered_set<int> rootSet;

        // 집합 생성
        for (int i = 0; i < n; i++) set.push_back(i);

        // 각 컴퓨터와 연결된 컴퓨터 저장
        for(int i =0; i< n; i++)
            for (int j = 0; j < n;j++)
            {
                if (i != j && computers[i][j] == 1)
                    adjList[i].push_back(j);
            }
        
        for (int com = 0; com < n; com++)
        {
            // 연결된 컴퓨터를 가져와 하나의 네트워크인지 확인 후 삽입
            if(adjList[com].size() > 0)
                for (int connectedCom : adjList[com])
                {
                    unionSet(connectedCom, com);
                }
        }

        for (int i = 0; i < n; i++)
        {
            int root = find(set[i]);
            if (rootSet.find(root) == rootSet.end())
            {
                answer++;
                rootSet.insert(root);
            }
        }

        return answer;
    }
}

namespace P42_Answer
{
    vector<bool> visited;

    // 깊이 우선 탐색(DFS)을 수행하는 함수
    void dfs(const vector<vector<int>>& network, int node) {
        visited[node] = true;

        for (int i = 0; i < network[node].size(); i++) {
            if (network[node][i] && !visited[i]) {
                dfs(network, i);
            }
        }
    }

    int solution(int n, vector<vector<int>> computers) {
        visited = vector<bool>(computers.size(), false);

        int networkCount = 0;

        // 네트워크의 수를 확인
        for (int i = 0; i < computers.size(); i++) {
            if (!visited[i]) {
                dfs(computers, i);
                networkCount++;
            }
        }

        return networkCount;
    }

}

//int main()
//{
//    vector<vector<int>> computers = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
//    int result2 = P42_Answer::solution(3, computers);
//
//        cout << result2 << " ";
//}
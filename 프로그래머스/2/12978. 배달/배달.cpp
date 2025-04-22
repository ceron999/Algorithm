#include <iostream>
#include <vector>
using namespace std;

 const int INF = 999999;
const int MAX_NODE = 51;
int graph[MAX_NODE][MAX_NODE];
bool visited[MAX_NODE];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    // 1. 그래프 및 방문여부 초기화
    for (int i = 0; i < MAX_NODE; i++)
    {
        fill_n(graph[i], MAX_NODE, INF);
        visited[i] = false;
    }

    // 간선 정보 추가
    for (vector<int> nowEdge : road)
    {
        int from = nowEdge[0];
        int to = nowEdge[1];
        int weight = nowEdge[2];

        if (graph[from][to] > weight)
        {
            graph[from][to] = weight;
            graph[to][from] = weight;
        }
    }

    vector<int> distance(N + 1, INF);
    distance[1] = 0;
    visited[1] = true;

    int from = 1;
    for (int count = 0; count < N; count++)
    {
        // 현재 from에서의 간선 업데이트
        for (int to = 1; to <= N; to++)
        {
            if (distance[to] > distance[from] + graph[from][to])
                distance[to] = distance[from] + graph[from][to];
        }

        visited[from] = true;

        // 다음 탐색 노드 찾기
        int minValue = INF;
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i] && distance[i] < minValue)
            {
                minValue = distance[i];
                from = i;
            }
        }
    }
    
    for (int dist : distance)
    {
        if (dist <= K)
            answer++;
    }

    return answer;
}
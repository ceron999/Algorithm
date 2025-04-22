/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12978
/// 배달
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P44
{
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
}

#include <queue>
namespace P44_Answer
{
    int solution(int N, vector<vector<int>> road, int K) {
        vector<vector<pair<int, int>>> graph(N + 1);
        vector<int> distances(N + 1, numeric_limits<int>::max());
        vector<bool> visited(N + 1, false);
        distances[1] = 0;

        // 방향이 따로 없으므로, 양방향 모두 동일한 가중치 입력
        for (const auto& r : road) {
            int a = r[0], b = r[1], cost = r[2];
            graph[a].push_back({ b, cost });
            graph[b].push_back({ a, cost });
        }

        // 출발점을 heap에 추가
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        heap.push({ 0, 1 });

        while (!heap.empty()) {
            int dist = heap.top().first;
            int node = heap.top().second;
            heap.pop();

            // 이미 방문한 노드는 무시
            if (visited[node]) continue;
            visited[node] = true;

            for (const auto& next : graph[node]) {
                int next_node = next.first;
                int next_dist = next.second;
                int cost = dist + next_dist;

                // 거쳐가는 노드로 가는 경로의 비용이 더 짧은 경우
                if (cost < distances[next_node]) {
                    distances[next_node] = cost;
                    heap.push({ cost, next_node });
                }
            }
        }

        int count = 0;

        // 거리가 K 이하인 장소를 카운트
        for (int i = 1; i <= N; i++) {
            if (distances[i] <= K) count++;
        }

        return count;
    }
}

//int main()
//{
//    vector<vector<int> > road =
//    { {1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1} };
//    int result2 = P44::solution(6, road, 4);
//
//        cout << result2 << " ";
//}
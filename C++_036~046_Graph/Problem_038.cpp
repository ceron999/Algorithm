/// <summary>
/// 
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
namespace P38
{
    class TableData
    {
    public:
        int weigh;
        int beforeNode;

        TableData(int weighNum, int beforeNum)
            : weigh(weighNum), beforeNode(beforeNum) {}
    };
    unordered_map<int, vector<pair<int,int>>> edgeMap;
    unordered_set<int> visited;
    vector<TableData> table;

    void dijkstra(int node)
    {
        if (visited.find(node) != visited.end()) return;

        visited.insert(node);
        // 1. 입력받은 노드에서 가능한 것들 테이블에 업데이트
        for (const auto& pair : edgeMap[node])
        {
            int destNode = pair.first;
            int weigh = pair.second;

            if (table[destNode].weigh > weigh)
            {
                table[destNode].weigh = table[node].weigh + weigh;
                table[destNode].beforeNode = node;
            }
        }

        // 2. table에서 선택x && 가장 작은 값을 찾아 또 진행
        int lowestNode = 1;
        for (int nextNode = 1; nextNode < table.size();nextNode++)
        {
            // 이미 사용되지 않고 weigh가 작으면 해당 노드 기억
            if (visited.find(nextNode) == visited.end())
            {
                if (table[nextNode].weigh < table[lowestNode].weigh)
                {
                    lowestNode = nextNode;
                }
            }
        }
        if (visited.find(lowestNode) == visited.end())
            dijkstra(lowestNode);
        else return;
    }

    vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges)
    {
        vector<int> answer;

        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b)
            {
                if(get<0>(a) != get<0>(b))
                    return get<0>(a) < get<0>(b);
                else
                    return get<1>(a) < get<1>(b);
            });

        for (auto& edge : edges)
        {
            int startNode = get<0>(edge);
            int destNode = get<1>(edge);
            int weigh = get<2>(edge);
            edgeMap[startNode].push_back({ destNode, weigh });
        }

        // 초깃값 설정
        for (int i = 0; i < numNodes; i++)
        {
            TableData newData({numeric_limits<int>::max(), numeric_limits<int>::max() });
            table.push_back(newData);
        }
        table[0].weigh = 0;
        table[0].beforeNode = 0;
        // 2. 다익스트라 알고리즘 시작
        dijkstra(start);
        
        for (const auto data : table)
        {
            answer.push_back(data.weigh);
        }
        return answer;
    }
}

const int INF = 99999;
const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

namespace P38_Answer
{
    

    vector<int> solution(int start, int numNodes, const vector<tuple<int, int, int>> edges) {
        // 그래프 및 방문 여부 초기화
        for (int i = 0; i < MAX_NODES; ++i) {
            fill_n(graph[i], MAX_NODES, INF);
            visited[i] = false;
        }

        // 입력받은 간선 정보를 그래프로 표현
        for (const auto& edge : edges)
        {
            int from = std::get<0>(edge);
            int to = std::get<1>(edge);
            int weight = std::get<2>(edge);
            graph[from][to] = weight;
        }

        // 시작 노드를 제외한 모든 노드의 최소 비용을 INF로 초기화
        vector<int> distances(numNodes, INF);
        distances[start] = 0;

        for (int i = 0; i < numNodes - 1; ++i) {
            int minDistance = INF;
            int closestNode = -1;

            // 최소 거리 노드 찾기
            for (int j = 0; j < numNodes; ++j) {
                if (!visited[j] && distances[j] < minDistance) {
                    minDistance = distances[j];
                    closestNode = j;
                }
            }

            // 찾은 노드를 방문 처리
            visited[closestNode] = true;

            // 인접 노드에 대한 거리 업데이트
            for (int j = 0; j < numNodes; ++j) {
                int newDistance = distances[closestNode] + graph[closestNode][j];
                if (!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) {
                    distances[j] = newDistance;
                }
            }
        }

        return distances;
    }
}
int main()
{
    vector<int> result2 = P38::solution(0, 3, {{0,1,9},{0,2,3} ,{1,0,5} ,{2,1,1} });

    for(int i : result2)
        cout << i << " ";
} 
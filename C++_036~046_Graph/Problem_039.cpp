/// <summary>
/// ���� ����
/// ���� ���� �˰���
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;


const int INF = numeric_limits<int>::max();

namespace P39
{
    vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source) {
        vector<vector<pair<int, int>>> graph(num_vertices);

        // ���������� Ȱ���ؼ� ��������Ʈ�� ����
        for (auto& edge : edges) {
            int from, to, weight;
            tie(from, to, weight) = edge;
            graph[from].emplace_back(to, weight);
        }

        // ������� ���� �ּҺ���� INF�� ����(���۳��� ����)
        vector<int> distance(num_vertices, INF);
        distance[source] = 0;

        // ������ ���� -1 ��ŭ �ּҺ���� ����
        for (int i = 0; i < num_vertices - 1; ++i) {
            for (int u = 0; u < num_vertices; ++u) {
                for (const auto& [v, weight] : graph[u]) {
                    if (distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                    }
                }
            }
        }

        // ���� ��ȯ�� �ִ��� Ȯ��
        for (int u = 0; u < num_vertices; ++u) {
            for (const auto& [v, weight] : graph[u]) {
                if (distance[u] + weight < distance[v]) {
                    return vector<int>(1, -1);
                }
            }
        }

        return distance;
    }
}

//int main()
//{
//    vector<tuple<int, int, int>> edges = {  {0,1,4},{0,2,3},{0,4,-6},{1,3,5},
//                                            {2,1,2},{3,0,7},{3,2,4},{4,2,2} };
//
//    vector<int> result2 = P39::solution(5, edges, 0);
//
//    for(int i : result2)
//        cout << i << " ";
//}
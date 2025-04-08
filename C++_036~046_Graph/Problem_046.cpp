/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/86971
/// 전력망 둘로 나누기
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
namespace P46
{
    int dfs(int node, int parent, const vector<vector<int>>& graph) {
        int cnt = 1;
        // 인접노드에 대해 깊이우선탐색 계속 진행
        for (int child : graph[node]) {
            // 무한탐색을 방지하기 위해 인접한 노드 중, 부모노드는 탐색하지 않음
            if (child != parent) {
                cnt += dfs(child, node, graph);
            }
        }
        return cnt;
    }

    int solution(int n, vector<vector<int>> wires) {
        vector<vector<int>> graph(n + 1);
        // wire정보를 활용해서 그래프 구축
        for (auto& wire : wires) {
            int a = wire[0];
            int b = wire[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int min_diff = INT_MAX;
        for (auto& wire : wires) {
            int a = wire[0];
            int b = wire[1];

            // 특정 전선을 임시로 삭제
            graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
            graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());

            // 전력망을 단절하고 각 전력망의 송전탑 개수의 차를 구함
            int cnt_a = dfs(a, b, graph);
            int cnt_b = n - cnt_a;

            // 현재까지 구한 송전탑의 차의 절대값의 최소값과 현재 값중 더 적은값을 택함
            min_diff = min(min_diff, abs(cnt_a - cnt_b));

            // 임시로 제거했던 제거했던 전선을 복구
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        return min_diff;
    }

}

int main()
{
    int result2 = P46::solution(9, { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}});

        cout << result2 << " ";
}
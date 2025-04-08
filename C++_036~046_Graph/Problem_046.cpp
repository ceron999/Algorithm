/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/86971
/// ���¸� �ѷ� ������
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
        // ������忡 ���� ���̿켱Ž�� ��� ����
        for (int child : graph[node]) {
            // ����Ž���� �����ϱ� ���� ������ ��� ��, �θ���� Ž������ ����
            if (child != parent) {
                cnt += dfs(child, node, graph);
            }
        }
        return cnt;
    }

    int solution(int n, vector<vector<int>> wires) {
        vector<vector<int>> graph(n + 1);
        // wire������ Ȱ���ؼ� �׷��� ����
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

            // Ư�� ������ �ӽ÷� ����
            graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
            graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());

            // ���¸��� �����ϰ� �� ���¸��� ����ž ������ ���� ����
            int cnt_a = dfs(a, b, graph);
            int cnt_b = n - cnt_a;

            // ������� ���� ����ž�� ���� ���밪�� �ּҰ��� ���� ���� �� �������� ����
            min_diff = min(min_diff, abs(cnt_a - cnt_b));

            // �ӽ÷� �����ߴ� �����ߴ� ������ ����
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
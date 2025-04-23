/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/92343
/// 양과 늑대
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
namespace P43_Answer
{

    vector<vector<int>> tree;
    vector<int> visited, infoData;
    int n, answer = 0;

    // 깊이 우선 탐색 (DFS)를 수행하는 함수
    void dfs(vector<int> currRoot) {
        int sheep = 0, wolf = 0;
        // 현재 방문한 경로를 기준으로 양과늑대의 개수를 셈
        for (int c : currRoot) {
            if (infoData[c] == 1) wolf++;
            else sheep++;
        }

        // 늑대의 수가 양보다 많거나 같으면 종료  
        if (sheep <= wolf) return;

        // 최대 양의 수 갱신
        answer = max(answer, sheep);

        for (int i = 0; i < currRoot.size(); i++) {
            int node = currRoot[i];

            // 현재 노드와 인접한 노드를 순회
            for (int child : tree[node]) {

                // 이미 방문한 노드는 재방문하지 않음
                if (visited[child]) continue;
                // 현재노드를 방문한 경우, 하지 않은 경우 모두 확인
                visited[child] = true;
                currRoot.push_back(child);
                dfs(currRoot);
                currRoot.pop_back();
                visited[child] = false;
            }
        }
    }

    int solution(vector<int> info, vector<vector<int>> edges) {
        n = info.size();
        tree.resize(n);
        visited.resize(n, false);
        infoData = info;

        // 입력값으로 부터 트리 생성
        for (auto e : edges) {
            tree[e[0]].push_back(e[1]);
        }

        visited[0] = true;
        // 방문여부를 체크하고, 시작 노드부터 탐색을 시작합니다.
        dfs({ 0 });
        return answer;
    }
}

int main()
{
    vector<int> info = { 0,0,1,1,1,0,1,0,1,0,1,1 };
    vector<vector<int>> edges = {
    {0,1}, {1,2}, {1,4}, {0,8}, {8,7},
    {9,10}, {9,11}, {4,3}, {6,5}, {4,6}, {8,9}
    };
    int result2 = P43_Answer::solution(info, edges);

        cout << result2 << " ";
}
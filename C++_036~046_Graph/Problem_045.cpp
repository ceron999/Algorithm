/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/67259
/// 경주로 건설
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
namespace P45
{
    const int dx[] = { 0, 0, -1, 1 };
    const int dy[] = { -1, 1, 0, 0 };
    const int STRAIGHT_COST = 100;
    const int CORNER_COST = 600;
    const int MAX_SIZE = 26;
    const int INF = numeric_limits<int>::max();

    struct Path {
        int y, x, direction;
    };

    bool isValid(int y, int x, int size) {
        return y >= 0 && y < size && x >= 0 && x < size;
    }

    int solution(vector<vector<int>> board) {
        int boardSize = static_cast<int>(board.size());
        int dist[MAX_SIZE][MAX_SIZE][4];
        memset(dist, -1, sizeof(dist));
        queue<Path> q;

        // 시작 지점의 방향에 따라 비용이 달라질수 있으므로 모든 경우의 수 고려  
        q.push({ 0, 0, 1 });
        q.push({ 0, 0, 3 });

        dist[0][0][1] = 0;
        dist[0][0][3] = 0;

        while (!q.empty()) {
            auto [y, x, dir] = q.front();
            q.pop();

            int lastCost = dist[y][x][dir];

            // 현재 지점을 기준으로 이동가능한 지점 확인  
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                // 다음 이동할 후보 지점이 board안에 있는 좌표이고, 도려가 연결되 있는 경우
                if (!isValid(ny, nx, boardSize) || board[ny][nx]) continue;

                int newCost = lastCost + (i == dir ? STRAIGHT_COST : CORNER_COST);

                // 아직 후보 지점을 방문하지 않았거나, 이전에 구했던 비용보다 더 적은 비용인 경우
                if (dist[ny][nx][i] == -1 || dist[ny][nx][i] > newCost) {
                    dist[ny][nx][i] = newCost;
                    q.push({ ny, nx, i });
                }
            }
        }

        // 도착 지점까지 가는 모든 경로 중 최소를 선택
        int answer = INF;
        for (int i = 0; i < 4; i++) {
            if (dist[boardSize - 1][boardSize - 1][i] != -1) {
                answer = min(answer, dist[boardSize - 1][boardSize - 1][i]);
            }
        }

        return answer == INF ? -1 : answer;
    }
}

int main()
{
    vector<vector<int>> board =
    {
        {0, 0, 0 },
        {0, 0, 0 },
        {0, 0, 0 },
    };

    vector<vector<int>> board2 =
    {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0}
    };
    int result2 = P45::solution(board2);

    
        std::cout << result2 << " ";
}
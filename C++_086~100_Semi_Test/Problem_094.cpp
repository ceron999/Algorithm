/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/81302
/// 거리두기 확인하기
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P94
{
    int dy[8] = { -1, -1, 0, 1, 1, 1, 0,-1 };
    int dx[8] = { 0,   1, 1, 1, 0,-1,-1,-1 };

    int d2y[4] = { -2, 0, 2, 0 };
    int d2x[4] = { 0, 2, 0, -2 };

    bool Search8Seat(const vector<string>& place, int row, int col)
    {
        // 8 방향 탐색
        for (int i = 0; i < 8; i++)
        {
            // 자리가 범위 내에 있을 경우만 탐색
            if (row + dy[i] >= 0 && row + dy[i] < 5 &&
                col + dx[i] >= 0 && col + dx[i] < 5)
            {
                // 1. p가 (row,col)위치에서 8방향 안에 p가 발견되었을 경우
                if (place[row + dy[i]][col + dx[i]] == 'P')
                {
                    if (i % 2 == 0)
                    {
                        // 거리가 1이므로 제외
                        return false;
                    }
                    else
                    {
                        // 대각선에 P가 위치하고 P와 P 사이에 X가 하나라도 존재하지 않으면 제외
                        if (place[row + dy[i]][col] != 'X' ||
                            place[row][col + dx[i]] != 'X')
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    bool Search4Seat(const vector<string>& place, int row, int col)
    {
        // 2칸 차이나는 4 방향 탐색
        for (int i = 0; i < 4; i++)
        {
            // 자리가 범위 내에 있을 경우만 탐색
            if (row + d2y[i] >= 0 && row + d2y[i] < 5 &&
                col + d2x[i] >= 0 && col + d2x[i] < 5)
            {
                if (place[row + d2y[i]][col + d2x[i]] == 'P')
                {
                    if (place[row + (d2y[i] / 2)][col + (d2x[i] / 2)] != 'X')
                        return false;
                }

            }
        }

        return true;
    }

    bool IsPlaceOk(const vector<string>& place)
    {
        for (int i = 0; i < place.size(); i++)
        {
            for (int j = 0; j < place[0].size(); j++)
            {
                // P를 발견하면 8방향의 좌석을 확인한다.
                if (place[i][j] == 'P')
                {
                    if (!Search8Seat(place, i, j))
                        return false;
                    if (!Search4Seat(place, i, j))
                        return false;
                }
            }
        }

        return true;
    }

    vector<int> solution(vector<vector<string>> places) 
    {
        vector<int> answer;

        // 각 장소가 유효한지 확인 후 삽입
        for (auto place : places)
        {
            if (IsPlaceOk(place))
                answer.push_back(1);
            else
                answer.push_back(0);
        }

        return answer;
    }
}

#include <queue>
namespace P94_Answer
{
    // x, y 위치에서 주변에 'P'가 있는지 검사
    bool hasClosePerson(const vector<string>& map, int N, int M, int x, int y) {
        const int dx[4] = { -1, 0, 1, 0 }; // 상하좌우 이동
        const int dy[4] = { 0, -1, 0, 1 };

        queue<pair<int, int>> q;
        bool visited[5][5] = {}; // 방문 여부
        visited[x][y] = true;
        q.push({ x, y });

        for (int layer = 0; layer < 2; layer++) {
            int size = q.size();
            while (size--) {
                pair<int, int> cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nextX = cur.first + dx[dir], nextY = cur.second + dy[dir];
                    if (!(0 <= nextX && nextX < 5 && 0 <= nextY && nextY < 5)) continue;
                    if (visited[nextX][nextY] || map[nextX][nextY] == 'X') continue;
                    if (map[nextX][nextY] == 'P') return true;
                    visited[nextX][nextY] = true;
                    q.push({ nextX, nextY });
                }
            }
        }
        return false;
    }

    // 지도 전체에서 'P'들이 규칙에 맞게 배치되었는지 확인
    bool isSafe(const vector<string>& map, int N, int M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 'P' && hasClosePerson(map, N, M, i, j)) return false;
            }
        }
        return true;
    }

    // 각 대기실 별로 안전한지 검사하여 결과 반환
    vector<int> solution(vector<vector<string>> places) {
        vector<int> answer;
        for (const auto& place : places) {
            answer.push_back(isSafe(place, 5, 5) ? 1 : 0);
        }
        return answer;
    }
}

int main()
{
    vector<vector<string>> places = 
    {
        { "POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP" },
        { "POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP" },
        { "PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX" },
        { "OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO" },
        { "PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP" }
    };
	vector<int> result = P94::solution(places);

	for (int i : result)
		cout << i << " ";
}
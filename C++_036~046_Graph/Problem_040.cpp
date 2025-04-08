/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/159993
/// �̷� Ż��
/// 
/// ���� ��ǰ
/// 1. DFS�� ���� Ǯ���� �Ͽ����� �ִ� �Ÿ��� BFS���� ����� �������� ���Ͽ���
/// 2. BFS�� ����� ������ �� ������
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
namespace P40
{
    vector<int> operator+(const vector<int>& a, const vector<int>& b)
    {
        vector<int> result;
        for (size_t i = 0; i < a.size(); i++)
            result.push_back(a[i] + b[i]);
        return result;
    }
    vector<vector<int>> visited;
    const vector<int> up = { 1,0 };
    const vector<int> down = { -1, 0 };
    const vector<int> right = { 0,1 };
    const vector<int> left = { 0,-1 };

    void BFS(const vector<string> &map, string& curr, vector<int> nowPos, bool isOpen)
    {
        
    }
    
    int solution(vector<string> maps)
    {
        int answer = 0;
        // ��Ʈ�� ��Ÿ���� ��� result �ʱ�ȭ
        string result = "";
        vector<int> start;

        // �����ϴ� ������ ã��
        for (int i = 0; i < maps.size(); i++)
            for (int j = 0; j < maps[0].size(); j++)
                if (maps[i][j] == 'S')
                    start = { i,j };


        // DPS ����
        BFS(maps, result, start, false);

        // ��Ʈ�� ���ڸ� ���� 
        answer = result.size();
        return answer;
    }
}

namespace P40_Answer
{
    // ���� ��ǥ��, �ش� ��ǥ���� �̵�Ƚ��
    struct Point {
        int y, x, cnt;
    };

    // �����¿�� �̵��ϱ� ���� ������
    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };
    int n, m;

    // ���� ��ǥ�� ��ȿ�� ��ǥ���� Ȯ��
    bool isWithinRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    // ���� ��ǥ�� Ȯ��
    Point findStartPoint(char start, vector<string>& maze) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == start) {
                    return { i, j, 0 };
                }
            }
        }
        return { -1, -1, -1 }; // �������� ã�� ���� ���
    }

    int bfs(char start, char end, vector<string>& maze) {

        // �湮���θ� üũ�ϴ� �迭
        bool visited[101][101] = { false };
        queue<Point> q;

        // ���۳����� �ʺ�켱 Ž���ϵ��� �߰�
        q.push(findStartPoint(start, maze));

        while (!q.empty()) {
            Point current = q.front();
            q.pop();

            // �������� ���������� �ش� ������ ���� �̵�Ƚ���� ��ȯ
            if (maze[current.y][current.x] == end) {
                return current.cnt;
            }
            // ������ġ ���� �����¿츦 Ȯ�� 
            for (int i = 0; i < 4; i++) {
                int ny = current.y + dy[i];
                int nx = current.x + dx[i];

                if (isWithinRange(ny, nx) && !visited[ny][nx] && maze[ny][nx] != 'X') {
                    // �ĺ���ǥ�� �̷� �������� �ְ�, ���� �湮���� �ʾ����� Ž��������� �߰�
                    q.push({ ny, nx, current.cnt + 1 });
                    visited[ny][nx] = true;
                }
            }
        }
        return -1;
    }

    int solution(vector<string> maps) {
        n = maps.size();
        m = maps[0].size();

        // ������������ L���� �ִܰŸ��� ���� 
        int distanceToL = bfs('S', 'L', maps);
        if (distanceToL == -1) return -1;

        // L���� ������������ �ִܰŸ��� ����
        int distanceToE = bfs('L', 'E', maps);
        return distanceToE == -1 ? -1 : distanceToL + distanceToE;
    }
}
//int main()
//{
//    int result2 = P40::solution({ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" });
//
//        cout << result2 << " ";
//}
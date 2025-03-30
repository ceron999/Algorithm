#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>

using namespace std;

class MoveController
{
public:
    pair<int, int> nowPosition;                     // ���� ��ġ
    map<pair<int, int>, vector<bool>> positionMap;  // map<��ġ, 4���� ���������� Ȯ�ο� bool>
    vector<vector<int>> moveOrder;                         // dir�� ���� �̵� ����
    int moveCount;                                  // �� �̵� Ƚ��

    MoveController(string getDIr)
    {
        nowPosition = { 0,0 };

        for(int x = -5; x <= 5; x++)
            for (int y = -5; y <= 5; y++)
            {
                pair<int, int> nowPos = { x,y };
                positionMap[nowPos] = { false, false, false, false };
            }

        for (char c : getDIr)
        {
            vector<int> direction;
            switch (c)
            {
                case 'U':
                    direction = { 0,1 };
                    break;
                case 'R':
                    direction = { 1,0 };
                    break;
                case 'D':
                    direction = { 0,-1 };
                    break;
                case 'L':
                    direction = { -1,0 };
                    break;
            }
            moveOrder.push_back(direction);
        }
        moveCount = 0;
    }
    ~MoveController()
    {
        moveOrder.clear();
    }

    bool IsAvailable(vector<int> dir)
    {
        // ���� ��ġ ����
        vector<int> nextPosition = { nowPosition.first + dir[0], nowPosition.second + dir[1] };

        // ���� ��ġ�� x,y�� ������ 5 �ʰ��� ����
        if (abs(nextPosition[0]) > 5 || abs(nextPosition[1]) > 5)
            return false;
        else
            return true;
    }

    bool IsPassed(vector<int> dir)
    {
        int dirIdx = 0;
        if (dir[0] == 1) dirIdx = 1; // R
        else if (dir[0] == -1) dirIdx = 3; // L
        else if (dir[1] == 1) dirIdx = 0; // U
        else if (dir[1] == -1) dirIdx = 2; // D
        else
            cout << "��ġ ���� ����!!!!!!!" << endl;

        // ���� ��ġ���� �̵� ������ �̵��ߴ��� ������ ��ȯ
        bool isPass = positionMap[nowPosition][dirIdx];
        UpdatePositionMap(dirIdx);
        return isPass;
    }

    void UpdatePositionMap(int dirIdx)
    {
        pair<int, int> newPosition;
        switch (dirIdx)
        {
            case 0:     // ��
                positionMap[nowPosition][0] = true;
                newPosition = { nowPosition.first, nowPosition.second + 1 };
                positionMap[newPosition][2] = true;
                break;
            case 1:     // ��
                positionMap[nowPosition][1] = true;
                newPosition = { nowPosition.first + 1, nowPosition.second };
                positionMap[newPosition][3] = true;
                break;
            case 2:     // ��
                positionMap[nowPosition][2] = true;
                newPosition = { nowPosition.first, nowPosition.second - 1 };
                positionMap[newPosition][0] = true;
                break;
            case 3:     // ��
                positionMap[nowPosition][3] = true;
                newPosition = { nowPosition.first - 1, nowPosition.second };
                positionMap[newPosition][1] = true;
                break;
        }
    }

    int CalculateMoveCount()
    {
        for (int i = 0; i < moveOrder.size(); i++)
        {
            if (!IsAvailable(moveOrder[i]))
                continue;

            if (IsPassed(moveOrder[i]))
            {
                Move(false, moveOrder[i]);
                continue;
            }
            // �̵�
            Move(true, moveOrder[i]);
        }

        return moveCount;
    }

    void Move(bool IsCount, vector<int> dir)
    {
        // �������� ī��Ʈ �Ѵ�
        if (IsCount)
        {
            nowPosition = { nowPosition.first + dir[0], nowPosition.second + dir[1] };
            moveCount++;
        }
        else
        {
            nowPosition = { nowPosition.first + dir[0], nowPosition.second + dir[1] };
        }
    }
};

int solution(string dirs) 
{
    int answer = 0;

    MoveController moveController(dirs);
    answer = moveController.CalculateMoveCount();
    cout << answer;
    return answer;
}

bool visited[11][11][4]; // Ư�� ��ǥ���� Ư�� �������� �̵��� ���� �ִ��� üũ�ϴ� �迭

// �����¿�� ��ǥ�� �̵��� �� �ʿ��� ��ǥ�� ������ �迭 
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

// �� ���ڿ� �ش��ϴ� ������ �迭�� �ε����� ��ȯ
int todir(char dir) {
    int ret;
    if (dir == 'U') ret = 0;
    else if (dir == 'R') ret = 1;
    else if (dir == 'D') ret = 2;
    else ret = 3;
    return ret;
}

// Ư����ǥ�� �־��� ��ǥ����� ������� Ȯ��
bool isNotValid(int x, int y)
{
    return x < 0 || y < 0 || x > 10 || y > 10;
}
// ����� �ݴ� ������ ������ �迭 �ε��� ��ȯ
int opposite_direction(int dir)
{
    return (dir + 2) % 4;
}

int solution2(string dirs)
{
    int answer = 0;
    int x = 5, y = 5; // ���� ��ǥ�� ����

    for (auto c : dirs) {
        // �ݺ����� ��ȸ�ϸ� nx, ny��  x, y�� dirs��� �������� �� ��ġ�� �� 
        int dir = todir(c);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // ��ǥ����� ��� ��� �� �̻� �̵����� ����
        if (isNotValid(nx, ny)) {
            continue;
        }

        // ���� ��ǥ�� ���� �湮���� ���� ��ǥ�� ���
        if (visited[y][x][dir] == false) {
            // �湮�� �ߺ� üũ���� �ʵ��� �ش� ����� ������� �湮 üũ
            visited[y][x][dir] = true;
            visited[ny][nx][opposite_direction(dir)] = true;
            answer++;
        }
        // ������ǥ�� �̵��� ��ǥ�� ������Ʈ
        x = nx;
        y = ny;
    }

    cout << answer;
    return answer;
}

int main()
{
    solution2("UUUUUUDDDDD");
}
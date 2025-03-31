#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>

using namespace std;

class MoveController
{
public:
    pair<int, int> nowPosition;                     // 현재 위치
    map<pair<int, int>, vector<bool>> positionMap;  // map<위치, 4방향 지나갔는지 확인용 bool>
    vector<vector<int>> moveOrder;                         // dir로 받은 이동 순서
    int moveCount;                                  // 총 이동 횟수

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
        // 다음 위치 설정
        vector<int> nextPosition = { nowPosition.first + dir[0], nowPosition.second + dir[1] };

        // 다음 위치의 x,y의 절댓값이 5 초과면 무시
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
            cout << "위치 설정 오류!!!!!!!" << endl;

        // 현재 위치에서 이동 방향을 이동했는지 변수를 반환
        bool isPass = positionMap[nowPosition][dirIdx];
        UpdatePositionMap(dirIdx);
        return isPass;
    }

    void UpdatePositionMap(int dirIdx)
    {
        pair<int, int> newPosition;
        switch (dirIdx)
        {
            case 0:     // 위
                positionMap[nowPosition][0] = true;
                newPosition = { nowPosition.first, nowPosition.second + 1 };
                positionMap[newPosition][2] = true;
                break;
            case 1:     // 우
                positionMap[nowPosition][1] = true;
                newPosition = { nowPosition.first + 1, nowPosition.second };
                positionMap[newPosition][3] = true;
                break;
            case 2:     // 아
                positionMap[nowPosition][2] = true;
                newPosition = { nowPosition.first, nowPosition.second - 1 };
                positionMap[newPosition][0] = true;
                break;
            case 3:     // 좌
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
            // 이동
            Move(true, moveOrder[i]);
        }

        return moveCount;
    }

    void Move(bool IsCount, vector<int> dir)
    {
        // 움직임을 카운트 한다
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
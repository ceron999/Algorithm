/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/120861
/// 캐릭터의 좌표
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P69
{
    int xMax;
    int yMax;

    const vector<int> up = { 0,1 };
    const vector<int> down = { 0,-1 };
    const vector<int> left = { -1,0 };
    const vector<int> right = { 1,0 };

    vector<int> pos = { 0,0 };

    vector<int> operator+=(vector<int>& nowPos, const vector<int>& dir)
    {
        nowPos = { pos[0] + dir[0], pos[1] + dir[1] };
        return nowPos;
    }

    void Move(const vector<int>& board, string nowKey)
    {
        switch (nowKey[0])
        {
        case 'u':
            if (pos[1] < yMax)
                pos += up;
            break;
        case 'd':
            if (pos[1] > (-1) * yMax)
                pos += down;
            break;
        case 'r':
            if (pos[0] < xMax)
                pos += right;
            break;
        case 'l':
            if (pos[0] > (-1) * xMax)
                pos += left;
            break;
        }
    }

    vector<int> solution(vector<string> keyinput, vector<int> board)
    {
        vector<int> answer;
        xMax = board[0] / 2;
        yMax = board[1] / 2;

        for (string nowKey : keyinput)
        {
            Move(board, nowKey);
        }

        answer = pos;
        return answer;
    }
}

int main()
{
    vector<int> result = P69::solution({ "left", "right", "up", "right", "right" }, { 11, 11 });

    for(int i : result)
        cout << i << " ";
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int result = 0;
vector<vector<bool>> queenLocateVector;

pair<int, int> getNextPosition(int row, int col)
{
    if (col == N - 1)
        return { row + 1, 0 };
    else
        return { row, col + 1 };
}

// 보드 안에 있으면 참
bool isWithinBoard(int row, int col)
{
    return (row >= 0 && row < N && col >= 0 && col < N);
}

// 해당 위치에서 가로, 세로 대각선에 퀸이 있는지 확인
bool canLocateQueen(int row, int col)
{
    for (int i = 0; i < N; i++)
    {
        if (queenLocateVector[row][i])
        {
            if (i == col) continue;
            return false;
        }
        if (queenLocateVector[i][col])
        {
            if (i == row) continue;
            return false;
        }
        if (i != 0)
        {
            if (isWithinBoard(row + i, col + i) && queenLocateVector[row + i][col + i]) return false;
            if (isWithinBoard(row + i, col - i) && queenLocateVector[row + i][col - i]) return false;
            if (isWithinBoard(row - i, col + i) && queenLocateVector[row - i][col + i]) return false;
            if (isWithinBoard(row - i, col - i) && queenLocateVector[row - i][col - i]) return false;
        }
    }

    return true;
}

void solveNQueen(int row, int col)
{
    // 1. 종료 시점
    if (row == N)
    {
        result++;
        return;
    }

    // 백트래킹
    for (int i = 0; i < N; i++)
    {
        // 퀸을 둘 수 있다면 해당 위치에 퀸을 두고 다음 칸을 찾는다
        if (canLocateQueen(row, i))
        {
            queenLocateVector[row][i] = true;
            solveNQueen(row + 1, 0);
            queenLocateVector[row][i] = false;
        }
    }
}

int solution(int n)
{
    int answer = 0;
    N = n;
    queenLocateVector.resize(n, vector<bool>(n, false));

    solveNQueen(0,0);
    answer = result;
    return answer;
}
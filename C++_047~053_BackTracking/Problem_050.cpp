/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12952
/// N-Queen
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P50
{
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
}

namespace P50_Answer
{
    // 현재 행에 이미 다른 퀸이 있는지 확인하는 함수
    bool isSameRow(int placedRow, int currentRow) {
        return placedRow == currentRow;
    }

    // 대각선에 다른 퀸이 있는지 확인하는 함수
    bool isDiagonalAttack(int placedCol, int placedRow, int currentCol, int currentRow) {
        return abs(placedCol - currentCol) == abs(placedRow - currentRow);
    }

    // 퀸을 안전하게 배치할 수 있는지 확인하는 함수
    bool isSafePosition(const vector<int>& queen, int col, int row) {
        for (int i = 0; i < col; ++i) {
            if (isSameRow(queen[i], row) || isDiagonalAttack(i, queen[i], col, row)) {
                return false;
            }
        }
        return true;
    }

    // 퀸을 배치하는 함수
    long long placeQueens(vector<int>& queen, int col) {
        int n = queen.size();
        if (col == n) {
            return 1;
        }

        long long count = 0;
        for (int row = 0; row < n; ++row) {
            // 퀸을 놓을수 있는 위치인 경우 퀸을 놓음
            if (isSafePosition(queen, col, row)) {
                queen[col] = row;
                count += placeQueens(queen, col + 1);
                queen[col] = -1;
            }
        }
        return count;
    }

    long long solution(int n) {
        vector<int> queen(n, -1);

        // 퀸을 놓을수 있는 경우의 수를 반환
        return placeQueens(queen, 0);
    }
}

//int main()
//{
//    int result = P50_Answer::solution(4);
//
//        cout << result << " ";
//}
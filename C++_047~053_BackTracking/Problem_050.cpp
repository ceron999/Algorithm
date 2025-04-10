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

    // ���� �ȿ� ������ ��
    bool isWithinBoard(int row, int col)
    {
        return (row >= 0 && row < N && col >= 0 && col < N);
    }

    // �ش� ��ġ���� ����, ���� �밢���� ���� �ִ��� Ȯ��
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
        // 1. ���� ����
        if (row == N)
        {
            result++;
            return;
        }

        // ��Ʈ��ŷ
        for (int i = 0; i < N; i++)
        {
            // ���� �� �� �ִٸ� �ش� ��ġ�� ���� �ΰ� ���� ĭ�� ã�´�
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
    // ���� �࿡ �̹� �ٸ� ���� �ִ��� Ȯ���ϴ� �Լ�
    bool isSameRow(int placedRow, int currentRow) {
        return placedRow == currentRow;
    }

    // �밢���� �ٸ� ���� �ִ��� Ȯ���ϴ� �Լ�
    bool isDiagonalAttack(int placedCol, int placedRow, int currentCol, int currentRow) {
        return abs(placedCol - currentCol) == abs(placedRow - currentRow);
    }

    // ���� �����ϰ� ��ġ�� �� �ִ��� Ȯ���ϴ� �Լ�
    bool isSafePosition(const vector<int>& queen, int col, int row) {
        for (int i = 0; i < col; ++i) {
            if (isSameRow(queen[i], row) || isDiagonalAttack(i, queen[i], col, row)) {
                return false;
            }
        }
        return true;
    }

    // ���� ��ġ�ϴ� �Լ�
    long long placeQueens(vector<int>& queen, int col) {
        int n = queen.size();
        if (col == n) {
            return 1;
        }

        long long count = 0;
        for (int row = 0; row < n; ++row) {
            // ���� ������ �ִ� ��ġ�� ��� ���� ����
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

        // ���� ������ �ִ� ����� ���� ��ȯ
        return placeQueens(queen, 0);
    }
}

//int main()
//{
//    int result = P50_Answer::solution(4);
//
//        cout << result << " ";
//}
/// <summary>
/// ���� ����
/// ������ ����
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
namespace P48
{
    bool isEnd = false;
    vector<vector<int>> result;
    vector<vector<int>> nowBoard;

    // row,col�� ��ġ�� 3x3 �簢���� ù ��ġ ã��
    vector<int> GetSquare(int row, int col)
    {
        int squareRow =  (row / 3) * 3;
        int squareCol =  (col / 3) * 3;

        return { squareRow ,squareCol };
    }

    bool isAvailable(int input, int row, int col)
    {
        // nowBoard���� board[row][0~8]�� �� ���� set
        unordered_set<int> rowNums;
        // nowBoard���� board[0~8][col]�� �� ���� set
        unordered_set<int> colNums;
        // nowBoard���� board[3x3]�� �� ���� set
        unordered_set<int> squareNums;


        vector<int> nowSquare = GetSquare(row, col);
        for (int i = 0; i < 9; i++)
        {
            rowNums.insert(nowBoard[row][i]);
            colNums.insert(nowBoard[i][col]);
            squareNums.insert(nowBoard[nowSquare[0] + i / 3][nowSquare[1] + i % 3]);
        }

        if (rowNums.find(input) != rowNums.end()) return false;
        if (colNums.find(input) != colNums.end()) return false;
        if (squareNums.find(input) != squareNums.end()) return false;

        return true;

    }

    void backTrack( int row, int col)
    {
        if (isEnd) return;

        // ���� ����
        if (row >= 8 && col >= 8 && nowBoard[row][col] != 0)
        {
            result = nowBoard;
            isEnd = true;
            return;
        }

        // ���� 0�� ã�������� �̵�
        if (nowBoard[row][col] != 0)
        {
            if (col == 8)
            {
                backTrack(row + 1, 0);
                return;
            }
            else
            {
                backTrack(row, col + 1);
                return;
            }
        }

        // ���� 0�� ã�Ҵٸ� ���⼭ �� �߰�
        for (int i = 1; i <= 9; i++)
        {
            if (isAvailable(i, row, col))
            {
                nowBoard[row][col] = i;
                if (col == 8)
                    backTrack(row + 1, 0);
                else
                    backTrack(row, col + 1);
                nowBoard[row][col] = 0;
            }
        }
    }

    vector<vector<int>> solution(vector<vector<int>> board)
    {
        vector<vector<int>> answer;
        nowBoard = board;

        backTrack(0, 0);
        answer = result;
        return answer;
    }
}
namespace P48_Answer
{
    vector<vector<int>> board; // ���� ������ ������ ���� ����

    // Ư�� ��ġ�� ���ڸ� ���� �� �ִ��� Ȯ��
    bool is_valid(int num, int row, int col) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) return false;
        }

        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == num) return false;
            }
        }
        return true;
    }

    // ���� ���ڰ� �Էµ��� ���� ��ġ�� Ȯ�� 
    pair<int, int> find_empty_position() {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == 0) return { row, col };
            }
        }
        return { -1, -1 };
    }

    void solve_sudoku() {
        pair<int, int> pos = find_empty_position();

        // �̹� ��� ĭ�� ä�����ٸ� ������ ����
        if (pos.first == -1) {
            return;
        }

        for (int num = 1; num <= 9; num++) {
            if (is_valid(num, pos.first, pos.second)) {
                board[pos.first][pos.second] = num;
                solve_sudoku();
                // ������ �ϼ��� ��� ���̻� Ž������ �ʱ� ���� ����
                if (find_empty_position().first == -1) return;
                board[pos.first][pos.second] = 0;
            }
        }
    }

    vector<vector<int>> solution(vector<vector<int>> input_board) {
        // ���ڷ� ���� ���带 ���� ������ �����ϰ� ������ ����
        board = input_board;
        solve_sudoku();
        return board;
    }

}
//int main()
//{
//    vector<vector<int>> board =
//    {
//        {5, 3, 0, 0, 7, 0, 0, 0, 0},
//        {6, 0, 0, 1, 9, 5, 0, 0, 0},
//        {0, 9, 8, 0, 0, 0, 0, 6, 0},
//        {8, 0, 0, 0, 6, 0, 0, 0, 3},
//        {4, 0, 0, 8, 0, 3, 0, 0, 1},
//        {7, 0, 0, 0, 2, 0, 0, 0, 6},
//        {0, 6, 0, 0, 0, 0, 2, 8, 0},
//        {0, 0, 0, 4, 1, 9, 0, 0, 5},
//        {0, 0, 0, 0, 8, 0, 0, 7, 9}
//    };
//
//    vector<vector<int>> result2 = P48::solution(board);
//
//    for (int i=0; i < result2.size() ; i++)
//    {
//        for (int j = 0; j < result2[0].size(); j++)
//            cout << result2[i][j] << " ";
//        cout << endl;
//    }
//}
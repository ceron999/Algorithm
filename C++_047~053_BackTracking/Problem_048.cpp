/// <summary>
/// 저자 출제
/// 스도쿠 퍼즐
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

    // row,col이 위치한 3x3 사각형의 첫 위치 찾기
    vector<int> GetSquare(int row, int col)
    {
        int squareRow =  (row / 3) * 3;
        int squareCol =  (col / 3) * 3;

        return { squareRow ,squareCol };
    }

    bool isAvailable(int input, int row, int col)
    {
        // nowBoard에서 board[row][0~8]에 들어간 숫자 set
        unordered_set<int> rowNums;
        // nowBoard에서 board[0~8][col]에 들어간 숫자 set
        unordered_set<int> colNums;
        // nowBoard에서 board[3x3]에 들어간 숫자 set
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

        // 종료 조건
        if (row >= 8 && col >= 8 && nowBoard[row][col] != 0)
        {
            result = nowBoard;
            isEnd = true;
            return;
        }

        // 다음 0을 찾을때까지 이동
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

        // 현재 0을 찾았다면 여기서 값 추가
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
    vector<vector<int>> board; // 전역 변수로 스도쿠 보드 선언

    // 특정 위치에 숫자를 놓을 수 있는지 확인
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

    // 아직 숫자가 입력되지 않은 위치를 확인 
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

        // 이미 모든 칸이 채워졌다면 수도쿠 종료
        if (pos.first == -1) {
            return;
        }

        for (int num = 1; num <= 9; num++) {
            if (is_valid(num, pos.first, pos.second)) {
                board[pos.first][pos.second] = num;
                solve_sudoku();
                // 스도쿠가 완성된 경우 더이상 탐색하지 않기 위핸 조건
                if (find_empty_position().first == -1) return;
                board[pos.first][pos.second] = 0;
            }
        }
    }

    vector<vector<int>> solution(vector<vector<int>> input_board) {
        // 인자로 받은 보드를 전역 변수에 복사하고 스도쿠 진행
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
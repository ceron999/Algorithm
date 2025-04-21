/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12905
/// 가장 큰 정사각형 찾기
/// 못풀음
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P78
{
    int solution(vector<vector<int>> board)
    {
        int answer = 1234;
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> maxLengthArr(row, vector<int>(col, 0));

        int maxLength = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 || j == 0)
                    maxLengthArr[i][j] = board[i][j];
                else if (board[i][j] == 1)
                {
                    maxLengthArr[i][j] = min({ maxLengthArr[i - 1][j], maxLengthArr[i][j - 1], maxLengthArr[i - 1][j - 1] }) + 1;
                }
                maxLength = max(maxLength, maxLengthArr[i][j]);
            }
        }
        answer = maxLength * maxLength;
        return answer;
    }
}

int main()
{
    vector<vector<int>> board =
    {
        {0,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {0,0,1,0}
    };
    int result = P78::solution(board);

        cout << result << " ";
}
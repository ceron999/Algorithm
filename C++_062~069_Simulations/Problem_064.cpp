/// <summary>
/// 저자 출제
/// 달팽이 수열 만들기
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P64
{
    int N;
    vector<int> dy = { 0, 1, 0, -1 };
    vector<int> dx = { 1, 0, -1, 0 };

    bool IsWIthinArr(const vector<vector<int>>& nowVec, const int& yPos, const int& xPos)
    {
        // 배열 내부에 있는가?
        if (xPos >= 0 && xPos < N && yPos >= 0 && yPos < N)
        {
            // 배열 내부에서 해당 위치의 값이 0이면 참
            if (nowVec[yPos][xPos] == 0) return true;
            else return false;
        }

        return false;
    }

    vector<vector<int>> solution(int n)
    {
        vector <vector<int>> answer;
        answer.resize(n, vector<int>(n, 0));
        N = n;

        int nSquare = n * n;
        int curr_y = 0;
        int curr_x = 0;
        int dirIdx = 0;

        answer[0][0] = 1;
        for (int i = 2; i <= nSquare;)
        {
            if (IsWIthinArr(answer, curr_y + dy[dirIdx], curr_x + dx[dirIdx]))
            {
                curr_y = curr_y + dy[dirIdx];
                curr_x = curr_x + dx[dirIdx];
                answer[curr_y][curr_x] = i;

                i++;
            }
            else
            {
                if (dirIdx == n - 1) dirIdx = 0;
                else
                    dirIdx++;
            }
        }

        return answer;

    }
}

namespace P65_Answer
{
    vector<vector<int>> solution(int n) {

        // N*N 2차원 벡터를 선언하고 초깃값을 0으로 함
        vector<vector<int>> snail_array(n, vector<int>(n, 0));
        int num = 1;
        // 행과 열의 시작과 끝 인덱스를 설정
        int start_row = 0, end_row = n - 1;
        int start_col = 0, end_col = n - 1;

        // 제일 외각부터 달팽이 수열 규칙대로 채움
        while (start_row <= end_row && start_col <= end_col) {
            // 가장 왼쪽 윗부분 에서 가장 아래 바로 직전 까지  채우기
            for (int i = start_col; i <= end_col; ++i) {
                snail_array[start_row][i] = num++;
            }
            ++start_row;

            // 가장 왼쪽  아래부분 에서 가장 오른쪽 바로 직전 까지 채우기
            for (int i = start_row; i <= end_row; ++i) {
                snail_array[i][end_col] = num++;
            }
            --end_col;

            // 가장 오른쪽 아래부분 에서 가장 위 바로 직전 까지 채우기
            if (start_row <= end_row) {
                for (int i = end_col; i >= start_col; --i) {
                    snail_array[end_row][i] = num++;
                }
                --end_row;
            }

            // 가장 윗부분 에서 가장 왼쪽 바로 직전 까지 채우기
            if (start_col <= end_col) {
                for (int i = end_row; i >= start_row; --i) {
                    snail_array[i][start_col] = num++;
                }
                ++start_col;
            }
        }

        return snail_array;
    }
}

//int main()
//{
//    vector<vector<int>> result = P64::solution(4);
//
//    for (int i = 0; i < result.size(); i++)
//    {
//        for (int j = 0; j < result[0].size(); j++)
//            cout << result[i][j] << " ";
//        cout << endl;
//    }
//}
/// <summary>
/// ���� ����
/// ������ ���� �����
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
        // �迭 ���ο� �ִ°�?
        if (xPos >= 0 && xPos < N && yPos >= 0 && yPos < N)
        {
            // �迭 ���ο��� �ش� ��ġ�� ���� 0�̸� ��
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

        // N*N 2���� ���͸� �����ϰ� �ʱ갪�� 0���� ��
        vector<vector<int>> snail_array(n, vector<int>(n, 0));
        int num = 1;
        // ��� ���� ���۰� �� �ε����� ����
        int start_row = 0, end_row = n - 1;
        int start_col = 0, end_col = n - 1;

        // ���� �ܰ����� ������ ���� ��Ģ��� ä��
        while (start_row <= end_row && start_col <= end_col) {
            // ���� ���� ���κ� ���� ���� �Ʒ� �ٷ� ���� ����  ä���
            for (int i = start_col; i <= end_col; ++i) {
                snail_array[start_row][i] = num++;
            }
            ++start_row;

            // ���� ����  �Ʒ��κ� ���� ���� ������ �ٷ� ���� ���� ä���
            for (int i = start_row; i <= end_row; ++i) {
                snail_array[i][end_col] = num++;
            }
            --end_col;

            // ���� ������ �Ʒ��κ� ���� ���� �� �ٷ� ���� ���� ä���
            if (start_row <= end_row) {
                for (int i = end_col; i >= start_col; --i) {
                    snail_array[end_row][i] = num++;
                }
                --end_row;
            }

            // ���� ���κ� ���� ���� ���� �ٷ� ���� ���� ä���
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
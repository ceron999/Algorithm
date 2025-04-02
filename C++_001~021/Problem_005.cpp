#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class P5
{
    vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

        int rowCount = (int)arr1.size();
        int colCount = (int)arr2[0].size();
        int indexCount = (int)arr2.size();

        vector<vector<int>> answer(rowCount, vector<int>(colCount));

        // arr1�� row ��� arr2�� col ���� idx������� ���� ���� �� answer[row,col]�� ����
        for (int row = 0; row < rowCount; row++)
        {
            for (int col = 0; col < colCount; col++)
            {
                int sum = 0;
                for (int idx = 0; idx < indexCount;idx++)
                {
                    sum += arr1[row][idx] * arr2[idx][col];
                }

                answer[row][col] = sum;
            }
        }

        return answer;
    }
};


//int main()
//{
//    vector<vector<int>> arr1 = {
//       {1, 4},
//       {3, 2},
//       {4, 1}
//    };
//
//    // �� ��° 2���� ����
//    vector<vector<int>> arr2 = {
//        {3, 3},
//        {3, 3}
//    };
//
//    solution(arr1, arr2);
//}



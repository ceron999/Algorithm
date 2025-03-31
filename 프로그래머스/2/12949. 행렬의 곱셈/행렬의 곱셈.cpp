#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    int rowCount = (int)arr1.size();
    int colCount = (int)arr2[0].size();
    int indexCount = (int)arr2.size();

    vector<vector<int>> answer(rowCount, vector<int>(colCount));

    // arr1의 row 행과 arr2의 col 열을 idx순서대로 곱해 더한 뒤 answer[row,col]에 저장
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
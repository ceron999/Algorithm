/// <summary>
/// 저자 출제
/// 시계방향 행렬 회전
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P62
{
    vector <vector<int>> RotateMatrix(vector <vector<int>> inputMatrix)
    {
        int size = inputMatrix.size();
        vector <vector<int>> result;
        result.resize(size, vector<int>(size, 0));

        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[0].size(); j++)
                result[j][size - 1 - i] = inputMatrix[i][j];
        }

        return result;
    }

    vector<vector<int>> solution(vector<vector<int>> arr, int n)
    {
        vector <vector<int>> answer;
        answer = arr;
        for (int i = 0; i < n; i++)
            answer = RotateMatrix(answer);

        return answer;

    }
}

//int main()
//{
//    vector<vector<int>> arr1 =
//    {
//        {1,2,3,4},
//        {5,6,7,8},
//        {9,10,11,12},
//        {13,14,15,16},
//    };
//
//    vector<vector<int>> result = P62::solution(arr1,2);
//
//    for (int i = 0; i < result.size(); i++)
//    {
//        for (int j = 0; j < result[0].size(); j++)
//            cout << result[i][j] << " ";
//        cout << endl;
//    }
//}
/// <summary>
/// 저자 출제
/// 두 행렬을 곱한 후 전치 행렬 만들기
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P63
{
    vector<vector<int>> TransposeMatrix(const vector<vector<int>>& arr)
    {
        vector <vector<int>> result(arr.size(), vector<int>(arr[0].size()));
        int matrixSize = arr[0].size();

        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[0].size(); j++)
            {
                result[i][j] = arr[j][i];
            }
        }

        return result;

    }

    vector<vector<int>> MultiplyMatrix(const vector<vector<int>>& arr1, const vector<vector<int>>& arr2)
    {
        vector <vector<int>> result(arr1.size(),vector<int>(arr2[0].size()));

        int matrixSize = arr1[0].size();

        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[0].size(); j++)
            {
                for (int k = 0; k < matrixSize; k++)
                    result[i][j] += (arr1[i][k] * arr2[k][j]);
            }
        }

        return result;

    }

    vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
    {
        vector <vector<int>> answer;
        
        answer = MultiplyMatrix(arr1, arr2);
        answer = TransposeMatrix(answer);

        return answer;

    }
}

//int main()
//{
//    vector<vector<int>> arr1 =
//    {
//        {1,2,3},
//        {4,5,6},
//        {7,8,9}
//    };
//
//    vector<vector<int>> arr2 =
//    {
//        {9,8,7},
//        {6,5,4},
//        {3,2,1}
//    };
//
//    vector<vector<int>> result = P63::solution(arr1,arr2);
//
//    for (int i = 0; i < result.size(); i++)
//    {
//        for (int j = 0; j < result[0].size(); j++)
//            cout << result[i][j] << " ";
//        cout << endl;
//    }
//}
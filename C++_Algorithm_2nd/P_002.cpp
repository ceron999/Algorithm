
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


namespace p2
{
    vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
        size_t rowSize = arr1.size();
        size_t colSize = arr2[0].size();

        vector<vector<int>> answer;
        answer.resize(rowSize, vector<int>(colSize, 0));

        for (int i = 0; i < answer.size(); i++)
        {
            for (int j = 0; j < answer[0].size(); j++)
            {
                for (int k = 0; k < arr1[0].size(); k++)
                    answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }

        return answer;
    }
}

//int main()
//{
//    vector<vector<int>> input1 = { {1, 4},{3, 2},{4, 1} };
//    vector<vector<int>> input2 = { {3, 3},{3, 3} };
//
//    vector<vector<int>>  result = p2::solution(input1, input2);
//
//    for (auto i : result)
//    {
//        for (auto j : i)
//            cout << j << ",";
//        cout << endl;
//    }
//
//}
/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/43105
/// Á¤¼ö »ï°¢¹ý
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P75
{
    
    int solution(vector<vector<int>> triangle) {
        int answer = 0;

        vector<vector<int>> sumTri = triangle;

        for (int i = 1; i < triangle.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                    sumTri[i][j] += sumTri[i - 1][j];
                else if(j == i)
                    sumTri[i][j] += sumTri[i - 1][j - 1];
                else
                {
                    int left = sumTri[i][j] + sumTri[i - 1][j];
                    int right = sumTri[i][j] + sumTri[i - 1][j - 1];
                    sumTri[i][j] = max(left, right);
                }
            }
        }

        answer = *max_element(sumTri[sumTri.size() - 1].begin(), sumTri[sumTri.size() - 1].end());
        return answer;
    }
}

//int main()
//{
//    vector<vector<int>> triangle = { {7} ,{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };
//    int result = P75::solution(triangle);
//
//        cout << result << " ";
//}
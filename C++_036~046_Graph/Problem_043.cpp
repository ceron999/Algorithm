/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/92343
/// ¾ç°ú ´Á´ë
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P43
{
    int solution(vector<int> info, vector<vector<int>> edges)
    {
        int answer = 0;
        return answer;
    }
}

int main()
{
    vector<int> info = { 0,0,1,1,1,0,1,0,1,0,1,1 };
    vector<vector<int>> edges = {
    {0,1}, {1,2}, {1,4}, {0,8}, {8,7},
    {9,10}, {9,11}, {4,3}, {6,5}, {4,6}, {8,9}
    };
    int result2 = P43::solution(info, edges);

        cout << result2 << " ";
}
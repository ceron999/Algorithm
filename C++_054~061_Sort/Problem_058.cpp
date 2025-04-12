/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42748
/// K��° ��
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace P58
{
    int GetKey(const vector<int> array, int i, int j, int k)
    {
        vector<int> divisionArray(array.begin() + i - 1, array.begin() + j);
        sort(divisionArray.begin(), divisionArray.end());
        return divisionArray[k - 1];
    }
    vector<int> solution(vector<int> array, vector<vector<int>> commands) 
    {
        vector<int> answer;

        for (const auto& nowCmd : commands)
        {
            int i = nowCmd[0];
            int j = nowCmd[1];
            int k = nowCmd[2];

            answer.push_back(GetKey(array, i, j, k));
        }

        return answer;
    }
}

namespace P58_Answer
{
    vector<int> solution(vector<int> array, vector<vector<int>> commands) {
        vector<int> answer;
        vector<int> subArray;

        for (const auto& cmd : commands) {
            // array���� �� cmd�� �ش�Ǵ� ������ subArray�� ������ ����
            subArray.assign(array.begin() + (cmd[0] - 1), array.begin() + cmd[1]);
            sort(subArray.begin(), subArray.end());

            // subArray���� k�� ° answer�� �߰�
            answer.push_back(subArray[cmd[2] - 1]);
        }

        return answer;
    }
}

//int main()
//{
//    vector<int> result2 = P58::solution({ 1, 5, 2, 6, 3, 7, 4 }, { {2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 }});
//
//    for(int i : result2)
//        cout << i << " ";
//}
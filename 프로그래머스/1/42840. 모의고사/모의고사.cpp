#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int answersSize = answers.size();

    vector<int> answerPattern_1 = { 1,2,3,4,5 };
    vector<int> answerPattern_2 = { 2,1,2,3,2,4,2,5, };
    vector<int> answerPattern_3 = { 3,3,1,1,2,2,4,4,5,5 };

    int result_1 = 0;
    int result_2 = 0;
    int result_3 = 0;

    for (int i = 0; i < answersSize;i++)
    {
        if (answers[i] == answerPattern_1[i % answerPattern_1.size()]) result_1++;
        if (answers[i] == answerPattern_2[i % answerPattern_2.size()]) result_2++;
        if (answers[i] == answerPattern_3[i % answerPattern_3.size()]) result_3++;
    }

    vector<pair<int, int>> results =
    {
        {1, result_1},
        {2, result_2},
        {3, result_3},
    };

    sort(results.begin(), results.end(), [](auto& a, auto& b) { return a.second > b.second; });

    answer.push_back(results[0].first);

    if(results[1].second == results[0].second)
        answer.push_back(results[1].first);

    if (results[2].second == results[0].second)
        answer.push_back(results[2].first);

    return answer;
}

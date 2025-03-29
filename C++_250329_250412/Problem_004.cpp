#include "Problem_004.h"

namespace Problem_004
{
    bool cmp(const pair<int, int>& a, const pair<int, int>& b) 
    {
        if (a.second == b.second) 
            return a.first < b.first;
        return a.second > b.second;
    }

    vector<int> solution(vector<int> answers) {
        vector<int> answer;

        // 1. 패턴 정립
        vector<int> aPattern = { 1,2,3,4,5 };
        vector<int> bPattern = { 2,1,2,3,2,4,2,5 };
        vector<int> cPattern = { 3,3,1,1,2,2,4,4,5,5 };

        // 2. a,b,c의 정답을 구현
        vector<vector<int>> inputs(3, vector<int>());
        for (int i =0; i< answers.size();i++)
        {
            inputs[0].push_back(aPattern[i % aPattern.size()]);
            inputs[1].push_back(bPattern[i % bPattern.size()]);
            inputs[2].push_back(cPattern[i % cPattern.size()]);
        }

        // 정답 수 확인
        vector<pair<int, int>> corrects = { {1,0}, {2,0},{3,0} };
        for (int i = 0; i < answers.size(); i++)
        {
            if (answers[i] == inputs[0][i]) corrects[0].second++;
            if (answers[i] == inputs[1][i]) corrects[1].second++;
            if (answers[i] == inputs[2][i]) corrects[2].second++;
        }

        sort(corrects.begin(), corrects.end(), cmp);
        
        for (pair<int, int> correct : corrects)
        {
            cout << correct.first << " " << correct.second << endl;
            if (correct.second != 0)
                answer.push_back(correct.first);
        }

        for (int i : answer)
        {
            cout << i << " ";
        }

        return answer;
    }
}
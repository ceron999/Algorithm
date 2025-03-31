#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


bool Compare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
{
    float aSuccessRate = (a.second.second ==0) ? 0.0f: (float)a.second.first / (float)a.second.second;
    float bSuccessRate = (b.second.second == 0) ? 0.0f : (float)b.second.first / (float)b.second.second;

    if (aSuccessRate == bSuccessRate)
        return a.first < b.first;
    else
        return aSuccessRate > bSuccessRate;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    // 1. map에 <스테이지, <성공한 사람 수, 도달한 사람 수>>를 설정
    vector<pair<int, pair<int, int>>> stageVector;
    for (int i = 1; i <= N + 1; i++)
    {
        stageVector.push_back({ i, {0,0} });
    }

    // 2. stages의 값을 하나씩 읽어 본인 미만의 스테이지에 성공한 사람 수 ++, 본인 이하 스테이지에 도달한 사람 수++ 진행
    // stageMaps[현재 스테이지] = (성공한 사람 수, 도전한 사람 수)
    for (int nowStage : stages)
    {
        for (int idx = 0; idx < N; idx++)
        {
            if (idx < nowStage - 1)
            {
                // 현재 스테이지에 도달하면 도달한 사람 수만 ++
                stageVector[idx].second.second++;
                continue;
            }
            else if(idx == nowStage - 1)
            {
                stageVector[idx].second.first++;
                stageVector[idx].second.second++;
            }
        }
    }

    // 3. stageMaps를 성공률이 낮은 순서대로 Sort한다.
    sort(stageVector.begin(), stageVector.end(), Compare);

    for (auto i : stageVector)
    {
        if (i.first == N + 1) continue;

        answer.push_back(i.first);
        cout << i.first << " ";
    }

    cout << endl;
    return answer;
}
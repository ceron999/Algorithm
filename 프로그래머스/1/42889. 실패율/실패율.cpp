#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<int> stageRemainers(N + 2, 0);

    for (int nowStage : stages)
    {
        stageRemainers[nowStage]++;
    }

    vector<pair<int, float>> failureRate;

    for (int i = 0; i < N + 1; i++)
    {
        failureRate.push_back({ i, 0 });
    }

    float remainCount = stages.size();

    for (int nowStage = 1; nowStage <= N; nowStage++)
    {
        if (remainCount == 0)
        {
            failureRate[nowStage].second = 0;
            continue;
        }
        failureRate[nowStage].second = (float)stageRemainers[nowStage] / remainCount;
        remainCount -= stageRemainers[nowStage];
    }

    sort(failureRate.begin(), failureRate.end(), [](auto& a, auto& b)
        {
            if (a.second != b.second)
                return a.second > b.second;
            
            return a.first < b.first;
        });

    for (auto result : failureRate)
    {
        if (result.first == 0)
            continue;

        answer.push_back(result.first);
    }

    return answer;
}
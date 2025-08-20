
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/// <summary>
/// 실패율 : 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수
/// 
/// 전체 스테이지의 개수 N
/// 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages
/// 
/// 실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return
/// 
/// </summary>
namespace p3
{
    vector<int> solution(int N, vector<int> stages) {
        vector<int> answer;

        vector<int> stageRemainers(N + 2, 0);

        for (int nowStage : stages)
        {
            stageRemainers[nowStage]++;
        }

        vector<pair<int, float>> failureRate;

        for (int i = 0; i <= N; i++)
        {
            failureRate.push_back({ i, 0 });
        }

        float remainCount = stages.size();

        for (int nowStage = 1; nowStage <= N; nowStage++)
        {
            if (remainCount == 0)
            {
                failureRate[nowStage].second = 1;
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
}

//int main()
//{
//    vector<int> input1 = { 2, 1, 2, 6, 2, 4, 3, 3 };
//
//    vector<int>  result = p3::solution(8, input1);
//
//    for (auto j : result)
//        cout << j << ",";
//
//}
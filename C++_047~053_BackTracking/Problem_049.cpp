/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/87946
/// 피로도
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P49
{
    vector<vector<int>> resultDungeons;
    vector<vector<int>> currDungeons;

    void backTrack(int nowK, vector<vector<int>> remainDungeons)
    {
        // 1. 남아있는 던전이 없으면 반환
        if (remainDungeons.size() == 0) 
        {
            if (currDungeons.size() > resultDungeons.size())
                resultDungeons = currDungeons;
            return;
        }

        // 2. 남은 던전을 다 돌아도 최댓값 갱신이 안되면 중단
        if (currDungeons.size() + remainDungeons.size() < resultDungeons.size()) return;

        // 3. 백트래킹
        for (int i =0; i< remainDungeons.size(); i++)
        {
            vector<vector<int>> newRemain = remainDungeons;

            // 던전 못들어가면 해당 던전 제거
            if (remainDungeons.size() > 0 && nowK < remainDungeons[i][0])
            {
                newRemain.erase(newRemain.begin() + i);
                backTrack(nowK, newRemain);
                return;
            }

            currDungeons.push_back(remainDungeons[i]);

            // 남은 던전 업데이트
            newRemain.erase(newRemain.begin() + i);

            backTrack(nowK - remainDungeons[i][1], newRemain);
            currDungeons.pop_back();
        }

    }

    int solution(int k, vector<vector<int>> dungeons) 
    {
        int answer = -1;

        backTrack(k, dungeons);
        answer = (resultDungeons.size() != 0) ? resultDungeons.size() : -1;
        return answer;
    }
}

namespace P49_Answer
{
    int maxDepth = 0;
    bool visited[8] = { false, };

    // 최대방문 던전수를 갱신하면서 깊이우선탐색으로 던전을 탐험
    void exploreDungeon(int depth, int power, vector<vector<int>>& dungeons) {
        if (maxDepth < depth)
            maxDepth = depth;

        for (int i = 0; i < dungeons.size(); i++) {
            // 이미 방문한 던전이거나,  최소 필요 피로도가 현재 남은 피로도 보다 많은 경우 
            if (visited[i] || dungeons[i][0] > power)
                continue;

            // 방문이 가능한 가능한 모든 경우를 확인
            visited[i] = true;
            exploreDungeon(depth + 1, power - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }

    int solution(int initialPower, vector<vector<int>> dungeons) {
        // 던전탐색 시작
        exploreDungeon(0, initialPower, dungeons);

        return maxDepth;
    }
}
//int main()
//{
//    int result2 = P49::solution(79, { { 80,20},{ 50,40 }, { 30,10 } });
//
//        std::cout << result2 << " ";
//}
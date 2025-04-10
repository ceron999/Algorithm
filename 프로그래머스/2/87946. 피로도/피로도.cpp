#include <string>
#include <vector>

using namespace std;

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
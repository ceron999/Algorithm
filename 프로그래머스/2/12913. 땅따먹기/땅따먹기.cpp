#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    vector<vector<int>> maxSumLand(land.size(), vector<int>(4, 0));
    int answer = 0;

    // 0번째 인덱스 열을 채운다
    for (int i = 0; i < 4; i++)
        maxSumLand[0][i] = land[0][i];

    // 이후 현재 행에서 해당 열을 선택했을 떄 최댓값을 갱신해 삽입한다.
    for (int i = 1; i < maxSumLand.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int upperMaxNum = 0;
            for (int upperColIndex = 0; upperColIndex < 4; upperColIndex++)
            {
                // 현재 선택한 j열과 i - 1행의 upperIndex가 같다면 
                // 같은 열을 연속해서 밟은 것으로 판단하여 제외
                if (upperColIndex != j)
                {
                    upperMaxNum = max(upperMaxNum, maxSumLand[i - 1][upperColIndex]);
                }
            }
            maxSumLand[i][j] = land[i][j] + upperMaxNum;
        }
    }

    answer = *max_element(maxSumLand[maxSumLand.size() - 1].begin(), maxSumLand[maxSumLand.size() - 1].end());

    return answer;
}
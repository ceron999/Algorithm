#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int zeroCount = 0;
    int correctCount = 0;

    for (int nowLottoNum : lottos)
        if (nowLottoNum == 0)
            zeroCount++;

    for (int nowWinNum : win_nums)
    {
        for (int nowLottoNum : lottos)
        {
            if(nowLottoNum == nowWinNum)
            {
                correctCount++;
                break;
            }
        }
    }

    int minRate, maxRate;
    switch (correctCount)
    {
    case 6:
        minRate = 1;
        maxRate = 1;
        break;
    case 5:
        minRate = 2;
        maxRate = minRate - zeroCount;
        break;
    case 4:
        minRate = 3;
        maxRate = minRate - zeroCount;
        break;
    case 3:
        minRate = 4;
        maxRate = minRate - zeroCount;
        break;
    case 2:
        minRate = 5;
        maxRate = minRate - zeroCount;
        break;
    default:
        minRate = 6;
        maxRate = minRate - zeroCount;
        break;
    }

    if (maxRate == 0)
        maxRate = 1;
    
    return { maxRate , minRate };
}
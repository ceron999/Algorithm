/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/77484
/// 로또의 최고 순위와 최저 순위
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P100
{
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
}

//int main()
//{
//    vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
//    vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
//	vector<int> result = P100::solution(lottos, win_nums);
//
//	for (int i : result)
//		cout << i << " ";
//}
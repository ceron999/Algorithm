/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42842?language=cpp
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P67
{
    vector<int> GetAvailableSquare(const vector<pair<int, int>>& pairs, const int& brown, const int& yellow)
    {
        for (const auto& pair : pairs)
        {
            int outSquare = (pair.first + pair.second) * 2 - 4;
            int inSquare = brown + yellow - outSquare;

            if (outSquare == brown && inSquare == yellow)
                return { pair.first, pair.second };
        }

        return {};
    }

    vector<pair<int, int>> FindSquareList(const int& sum)
    {
        vector<pair<int, int>> pairs;

        int sqrtNum = sqrt(sum);

        for (int i = 3; i <= sqrtNum; i++)
        {
            if (sum % i == 0)
            {
                pairs.push_back({ sum / i, i });
            }
        }

        return pairs;
    }

    vector<int> solution(int brown, int yellow) 
    {
        vector<int> answer;

        // 1. brown + yellow의 값에서 가능한 모든 사각형 리스트 찾기
        vector<pair<int, int>> pairs = FindSquareList(brown + yellow);

        // 2. 가능한 사각형 중 적합한 사각형 찾기
        answer = GetAvailableSquare(pairs, brown, yellow);

        return answer;
    }
}

int main()
{
    vector<int> result = P67::solution(10, 2);

    for(int i : result)
        cout << i << " ";
}
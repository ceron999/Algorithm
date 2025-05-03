/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/67258
/// 보석 쇼핑
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
namespace P98
{

    bool IsAllGemsConTain(const unordered_map<string, int>& gemsMap)
    {
        for (auto& gemNameAndCount : gemsMap)
        {
            if (gemNameAndCount.second == 0)
                return false;
        }

        return true;
    }
    vector<int> solution(vector<string> gems) {

        // 포함된 모든 보석 이름 저장
        unordered_map<string, int> gemsMap;

        int totalGemsCount = 0;
        for (string gem : gems)
        {
            if (gemsMap.find(gem) == gemsMap.end())
            {
                gemsMap[gem] = 0;
                totalGemsCount++;
            }
        }

        int rightIdx = gems.size() - 1;
        int leftIdx = 0;

        int validGemsCount = 0;
        int left = 0;
        for (int right = 0; right < gems.size(); right++)
        {
            if (gemsMap[gems[right]] == 0)
                validGemsCount++;

            gemsMap[gems[right]]++;

            while (validGemsCount == totalGemsCount)
            {
                if ((rightIdx - leftIdx) > (right - left))
                {
                    rightIdx = right;
                    leftIdx = left;
                }

                gemsMap[gems[left]]--;
                if (gemsMap[gems[left]] == 0)
                    validGemsCount--;

                left++;
            }
        }

        return { leftIdx + 1, rightIdx + 1 };
    }
}

//int main()
//{
//	vector<int> result = P98::solution({ "AA", "AB", "AC", "AA", "AC" });
//
//	for (int i : result)
//		cout << i << " ";
//}
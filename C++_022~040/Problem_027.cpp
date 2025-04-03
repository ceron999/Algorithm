/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/72411
/// 메뉴 리뉴얼
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
namespace P27
{
    vector<string> solution(vector<string> orders, vector<int> course) 
    {
        vector<string> answer;
        return answer;
    }
}

int main()
{
    vector<string> result = P27::solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
    for (string i : result)
        cout << i << " ";
}
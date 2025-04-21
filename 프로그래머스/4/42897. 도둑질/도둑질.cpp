#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) 
{
    // 0. 크기가 3 이하면 그냥 최댓값을 반환
    if (money.size() <= 3)
    {
        return *max_element(money.begin(), money.end());
    }

    vector<int> containFirst = money;
    

    containFirst.pop_back();
    containFirst[1] = max(containFirst[0], containFirst[1]);
    for (int i = 2; i < containFirst.size(); i++)
    {
        // 1. 첫번째를 포함할 경우
        containFirst[i] = max(containFirst[i - 1], containFirst[i - 2] + containFirst[i]);
    }


    vector<int> notContainFirst(money.begin() + 1, money.end());
    notContainFirst[1] = max(notContainFirst[0], notContainFirst[1]);

    // 2, 포함하지 않을 경우
    for (int i = 2; i < notContainFirst.size(); i++)
    {
        // 1. 첫번째를 포함할 경우
        notContainFirst[i] = max(notContainFirst[i - 1], notContainFirst[i - 2] + notContainFirst[i]);
    }

    int answer = max(containFirst.back(), notContainFirst.back());
    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int, int> tangerineMap;

    for (int i = 0; i < tangerine.size(); i++)
    {
        tangerineMap[tangerine[i]]++;
    }

    vector<pair<int, int>> tangerineVec(tangerineMap.begin(), tangerineMap.end());
    sort(tangerineVec.begin(), tangerineVec.end(), [](const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second > b.second;
        });

    for (auto nowSizeAndCount : tangerineVec)
    {
        if (k > nowSizeAndCount.second)
        {
            k -= nowSizeAndCount.second;
            answer++;
        }
        else
        {
            k = 0;
            answer++;
            break;
        }
    }

    return answer;
}
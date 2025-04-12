#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetKey(const vector<int> array, int i, int j, int k)
{
    vector<int> divisionArray(array.begin() + i - 1, array.begin() + j);
    sort(divisionArray.begin(), divisionArray.end());
    return divisionArray[k - 1];
}
vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;

    for (const auto& nowCmd : commands)
    {
        int i = nowCmd[0];
        int j = nowCmd[1];
        int k = nowCmd[2];

        answer.push_back(GetKey(array, i, j, k));
    }

    return answer;
}
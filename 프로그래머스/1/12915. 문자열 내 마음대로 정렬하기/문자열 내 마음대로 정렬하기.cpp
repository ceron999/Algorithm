#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    sort(strings.begin(), strings.end(), [n](const auto& a, const auto& b)
    {
        if (a[n] != b[n])
        {
            return (int)a[n] < (int)b[n];
        }
        else
        {
            for (int i = 0; i < a.size(); i++)
            {
                if(a[i] != b[i])
                    return (int)a[i] < (int)b[i];
            }
        }
    });

    answer = strings;

    return answer;
}
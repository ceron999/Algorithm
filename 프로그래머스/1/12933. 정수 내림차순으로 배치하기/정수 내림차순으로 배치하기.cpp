#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    vector<int> nVector;

    while (n != 0)
    {
        nVector.push_back(n % 10);
        n /= 10;
    }

    sort(nVector.begin(), nVector.end(), [](const auto& a, const auto& b)
        {
            return a > b;
        });
    
    while (!nVector.empty())
    {
        answer *= 10;
        answer += nVector[0];

        nVector.erase(nVector.begin());
    }

    return answer;
}
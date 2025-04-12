#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) 
{
    long long answer = 0;

    vector<int> nVec;
    while (n != 0)
    {
        nVec.push_back(n % 10);
        n /= 10;
    }

    sort(nVec.begin(), nVec.end(), [](const int& a, const int& b) { return a < b; });

    int size = 1;
    for (int nowNum : nVec)
    {
        answer += nowNum * size;
        size *= 10;
    }
    return answer;
}
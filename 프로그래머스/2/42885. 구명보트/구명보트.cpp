#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    sort(people.begin(), people.end(), [](const int& a, const int& b)
        {
            return a < b;
        });

    int startWeight = 0;
    int endWeight = people.size() - 1;

    while (startWeight <= endWeight)
    {
        if (people[startWeight] + people[endWeight] <= limit)
        {
            startWeight++;
        }

        endWeight--;

        answer++;
    }

    return answer;
}
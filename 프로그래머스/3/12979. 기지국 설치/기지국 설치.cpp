#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int stationsIdx = 0;
    for (int i = 1; i <= n;)
    {
        // 이미 5g의 영향을 받는 구간이라면 영향을 받지 않는 곳으로 점프한다.
        if (stationsIdx < stations.size() && stations[stationsIdx] - w <= i && i <= stations[stationsIdx] + w)
        {
            i = stations[stationsIdx] + w + 1;
            stationsIdx++;
        }
        else
        {
            answer++;
            i += 2 * w + 1;
        }

    }

    return answer;
}
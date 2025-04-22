/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12979
/// 기지국 설치
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P85
{

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
}

//int main()
//{
//    int n = 16;
//    vector<int> stations = { 9 };
//    int w = 2;
//    int result = P85::solution(n, stations, w);
//
//        cout << result << " ";
//}
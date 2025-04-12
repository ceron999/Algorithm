/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12933
/// 정수 내림차순으로 배치
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace P57
{
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
}

namespace P57_Answer
{
    long long solution(long long n) {
        // 숫자를 문자열로 변환
        string str = to_string(n);

        // 역순으로 정렬
        sort(str.rbegin(), str.rend());
        return stoll(str);
    }

}

//int main()
//{
//    long long result2 = P57::solution(118372);
//
//        cout << result2 << " ";
//}
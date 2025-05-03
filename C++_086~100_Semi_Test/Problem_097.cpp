/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12987?language=cpp
/// 숫자게임
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
namespace P97
{
    int solution(vector<int> A, vector<int> B) {
        int answer = 0;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int bIdx = 0;

        queue<int> q;
        for (int num : A)
            q.push(num);

        while (!q.empty())
        {
            if (bIdx == B.size())
                break;

            int nowNum = q.front();

            if (B[bIdx] > nowNum)
            {
                bIdx++;
                q.pop();

                answer++;
                continue;
            }
            else
            {
                bIdx++;
            }
        }

        return answer;
    }
}

//int main()
//{
//	int result = P97::solution({ 5,1,3,7 }, { 2,2,6,8 });
//
//		cout << result << " ";
//}
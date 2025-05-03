#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

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
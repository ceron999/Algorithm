#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // 1. 모든 진척도에 speed를 더함
    //2. 제일 앞 숫자가 100이 되었을 때 100 이상인 것 개수 싹 세어서 삽입
    // 반복

    while (!progresses.empty())
    {
        if (progresses[0] >= 100)
        {
            int count = 0;
            while (!progresses.empty() && progresses[0] >= 100)
            {
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                count++;
            }
            answer.push_back(count);
            continue;
        }

        for (int i = 0;i < progresses.size();i++)
        {
            progresses[i] += speeds[i];
        }
    }

    return answer;
}
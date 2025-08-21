
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

namespace p16
{
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

}
//void print(vector<int> vec)
//{
//    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
//    cout << endl;
//}

//int main()
//{
//    vector<int> input = { 93, 30, 55 };
//    vector<int> input2 = { 1, 30, 5 };
//
//    vector<int> i = p16::solution(input,input2);
//
//    print(i);
//}
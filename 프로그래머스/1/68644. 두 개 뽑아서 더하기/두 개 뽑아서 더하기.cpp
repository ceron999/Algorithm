#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;

    for (int i=0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size();j++ )
        {
            int sum = numbers[i] + numbers[j];
            answer.push_back(sum);
        }
    }

    //합을 정렬 후 중복 제거
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    for (const auto& n : answer) cout << n << ' ';
    cout << endl;

    return answer;
}
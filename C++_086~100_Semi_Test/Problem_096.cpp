/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/118667
/// 두 큐 합 같게 만들기
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P96
{
    int solution(vector<int> queue1, vector<int> queue2) {
        int answer = -2;
        return answer;
    }
}

int main()
{
    vector<int> queue1 = { 3, 2, 7, 2 };
    vector<int> queue2 = { 4, 6, 5, 1 };
	int result = P96::solution(queue1, queue2);

		cout << result << " ";
}
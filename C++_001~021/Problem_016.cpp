/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42586
/// 기능 개발
/// 
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
namespace P16
{
	vector<int> solution(vector<int> progresses, vector<int> speeds)
	{
		vector<int> answer;

		queue<int> leftDays;

		// 0. 만약 progress가 1개밖에 없으면 그냥 1 return
		if (progresses.size() == 1)
		{
			answer.push_back(1);
			return answer;
		}

		// 1. 출시까지 남은 일수를 출시 순서대로 큐에 삽입
		for (int i = 0; i < progresses.size(); i++)
		{
			int days = ceil((100.0 - progresses[i]) / speeds[i]);
			leftDays.push(days);
		}

		int nowDay = leftDays.front();
		leftDays.pop();
		int count = 1;		// 출시 때 나가는 개수 세기
		while (!leftDays.empty())
		{
			// 다음 순번의 기능 완성까지 남은 시간이 앞의 순번보다 빠르다면 같이 출시
			if (leftDays.front() <= nowDay)
			{
				leftDays.pop();
				count++;
			}
			else
			{
				// 처음으로 더 오래 걸리는 기능이 나오면 
				// 앞선 기능을 모두 더한 count를 삽입
				answer.push_back(count);
				nowDay = leftDays.front();
				leftDays.pop();
				count = 1;
			}
		}
		answer.push_back(count);

		return answer;
	}
}

//int main()
//{
//	vector<int> result = P16::solution({ 98, 98, 98, 98, 98, 99 }, { 1, 1, 1, 1, 1, 1 });
//	for (int i : result)
//		cout << i << " ";
//}
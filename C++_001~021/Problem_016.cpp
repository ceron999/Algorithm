/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42586
/// ��� ����
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

		// 0. ���� progress�� 1���ۿ� ������ �׳� 1 return
		if (progresses.size() == 1)
		{
			answer.push_back(1);
			return answer;
		}

		// 1. ��ñ��� ���� �ϼ��� ��� ������� ť�� ����
		for (int i = 0; i < progresses.size(); i++)
		{
			int days = ceil((100.0 - progresses[i]) / speeds[i]);
			leftDays.push(days);
		}

		int nowDay = leftDays.front();
		leftDays.pop();
		int count = 1;		// ��� �� ������ ���� ����
		while (!leftDays.empty())
		{
			// ���� ������ ��� �ϼ����� ���� �ð��� ���� �������� �����ٸ� ���� ���
			if (leftDays.front() <= nowDay)
			{
				leftDays.pop();
				count++;
			}
			else
			{
				// ó������ �� ���� �ɸ��� ����� ������ 
				// �ռ� ����� ��� ���� count�� ����
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
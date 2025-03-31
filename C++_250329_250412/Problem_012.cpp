/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42584
/// 
/// ��������
/// n�� ���� �ְ��� �� ������ ����� �迭 prices�� �Ű������� �־��� ��, 
/// �� ���� �ְ��� �������� �ش� �� ���� n�� ���̿� ������ �������� ���� �ð��� �� ������
/// �迭�� ��� return �ϵ��� solution �Լ��� �ϼ��ϼ���.
///
/// ���ѻ���
/// prices�� �� ������ 1 �̻� 10, 000 ������ �ڿ����Դϴ�.
/// prices�� ���� n�� 2 �̻� 100, 000 �����Դϴ�. (2 <= n <= 100, 000)
///
/// ����� ��
/// prices : [1, 2, 3, 2, 3]
/// return : [4, 3, 1, 1, 0]
///
/// ����� �� ����
/// 1���� �ְ��� 1�̸� 1�ʺ��� 5�ʱ��� �� 4�ʰ� �ְ��� �����߽��ϴ�.
/// 2���� �ְ��� 2�̸� 2�ʺ��� 5�ʱ��� �� 3�ʰ� �ְ��� �����߽��ϴ�.
/// 3���� �ְ��� 3�̸� 4���� �ְ��� 2�� �ְ��� ���������� 3�ʿ��� 4�ʰ� �Ǳ� ���������� 1�ʰ� �ְ��� ���� �Ȱ����� ���ϴ�.
/// ���� 5�ʱ��� �� 1�ʰ� �ְ��� �����߽��ϴ�.
/// 4���� �ְ��� 2�̸� 4�ʺ��� 5�ʱ��� �� 1�ʰ� �ְ��� �����߽��ϴ�.
/// 5���� �ְ��� 3�̸� 5�� ���ķδ� �����Ͱ� �����Ƿ� �� 0�ʰ� �ְ��� �����߽��ϴ�.
/// 
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>

using namespace std;
namespace P12
{
	vector<int> solution(vector<int> prices) {
		vector<int> answer(prices.size());

		for (int idx = 0; idx < prices.size(); idx++)
		{
			int count = 0;
			for (int nowNumIndex = idx + 1; nowNumIndex < prices.size(); nowNumIndex++)
			{
				if (prices[idx] > prices[nowNumIndex])
				{
					continue;
				}
				count++;
			}
			answer[idx] = count;
		}

		return answer;
	}
}

int main()
{
	vector<int> result = P12::solution({ 2,3,1,2,3 });

	for (int i : result)
	{
		cout << i << " ";
	}
}
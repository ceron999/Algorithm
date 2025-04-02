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

		for (int comparedIdx = 0; comparedIdx < prices.size(); comparedIdx++)
		{
			int count = 0;
			for (int comparingIdx = comparedIdx + 1; comparingIdx < prices.size(); comparingIdx++)
			{
				// ó������ ���ڰ� �۾����� count�� �� ���� �ʴ´�.
				if (prices[comparedIdx] > prices[comparingIdx])
				{
					count++;
					break;
				}
				count++;
			}
			if (comparedIdx == prices.size() - 1)
			{
				answer[comparedIdx] = 0;
			}
			else
				answer[comparedIdx] = count;
		}


		return answer;
	}

	// ���� ����
	vector<int> solution2(vector<int> prices) 
	{
		// ������ �������� ���� �Ⱓ�� ������ ����    
		vector<int> answer(prices.size());
		// ���ÿ��� prices�� �ε����� ��, ���� ���ݰ� ���� ������ ���ϱ� ���� �뵵�� ����  
		stack<int> s;

		int priceNum = prices.size();

		for (int i = 0;i < priceNum;i++) {
			while (!s.empty() && prices[s.top()] > prices[i]) {
				// ������ ���������Ƿ� ���� ������ �Ⱓ ��� 
				answer[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
		// ���ÿ� �����ִ� ���ݵ��� ������ �������� ���� ���
		while (!s.empty()) {
			answer[s.top()] = priceNum - s.top() - 1;
			s.pop();
		}
		return answer;
	}
}

//int main()
//{
//	vector<int> result = P12::solution2({ 1,2,3,2,3 });
//
//	for (int i : result)
//	{
//		cout << i << " ";
//	}
//}
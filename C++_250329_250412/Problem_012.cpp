/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42584
/// 
/// 문제설명
/// n초 간의 주가를 초 단위로 기록한 배열 prices가 매개변수로 주어질 때, 
/// 각 초의 주가를 기준으로 해당 초 부터 n초 사이에 가격이 떨어지지 않은 시간은 몇 초인지
/// 배열에 담아 return 하도록 solution 함수를 완성하세요.
///
/// 제한사항
/// prices의 각 가격은 1 이상 10, 000 이하인 자연수입니다.
/// prices의 길이 n은 2 이상 100, 000 이하입니다. (2 <= n <= 100, 000)
///
/// 입출력 예
/// prices : [1, 2, 3, 2, 3]
/// return : [4, 3, 1, 1, 0]
///
/// 입출력 예 설명
/// 1초의 주가는 1이며 1초부터 5초까지 총 4초간 주가를 유지했습니다.
/// 2초의 주가는 2이며 2초부터 5초까지 총 3초간 주가를 유지했습니다.
/// 3초의 주가는 3이며 4초의 주가는 2로 주가가 떨어졌지만 3초에서 4초가 되기 직전까지의 1초간 주가가 유지 된것으로 봅니다.
/// 따라서 5초까지 총 1초간 주가를 유지했습니다.
/// 4초의 주가는 2이며 4초부터 5초까지 총 1초간 주가를 유지했습니다.
/// 5초의 주가는 3이며 5초 이후로는 데이터가 없으므로 총 0초간 주가를 유지했습니다.
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
				// 처음으로 숫자가 작아지면 count를 더 세지 않는다.
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

	// 교재 정답
	vector<int> solution2(vector<int> prices) 
	{
		// 가격이 떨어지지 않은 기간을 저장한 벡터    
		vector<int> answer(prices.size());
		// 스택에는 prices의 인덱스가 들어감, 이전 가격과 현재 가격을 비교하기 위한 용도로 사용됨  
		stack<int> s;

		int priceNum = prices.size();

		for (int i = 0;i < priceNum;i++) {
			while (!s.empty() && prices[s.top()] > prices[i]) {
				// 가격이 떨어졌으므로 이전 가격의 기간 계산 
				answer[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
		// 스택에 남아있는 가격들은 가격이 떨어지지 않은 경우
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
#include <string>
#include <vector>
#include <stack>

using namespace std;

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
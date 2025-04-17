/// <summary>
/// 저자 출제
/// LIS 길이 계산하기
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P71
{
	vector<int> dp;
	int solution(const vector<int> nums)
	{
		dp.resize(nums.size(), 0);

		dp[0] = 1;

		int answer = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			int maxNum = 0;
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i] && maxNum < dp[j])
					maxNum = dp[j];
			}
			
			dp[i] = maxNum + 1;
			if (answer < dp[i]) answer = dp[i];
		}

		return answer;
	}
}

//int main()
//{
//    int result = P71::solution({1,4,2,3,1,5,7,3});
//
//        cout << result << " ";
//}
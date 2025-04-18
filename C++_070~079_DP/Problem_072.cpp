/// <summary>
/// 저자 출제
/// 조약돌 문제
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P72
{
	//dp[i, j]는 현재 위치를 선택했을 때 최댓값이라 가정
	vector<vector<int>> dp;

	int solution(vector<vector<int>> arr)
	{
		int n = arr.size();
		int m = arr[0].size();
		dp.resize(n + 1, vector<int>(m + 1, 0));

		int maxValue = numeric_limits<int>::min();
		for (int j = 1; j <= m; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				switch (i)
				{
				case 1:
					dp[i][j] = dp[2][j - 1] + arr[i - 1][j - 1];
					break;
				case 2:
					dp[i][j] = dp[3][j - 1] + arr[i - 1][j - 1];
					break;
				case 3:
					// i=0을 포함한 값 + 현재 위치값과 i=0을 포함하지 않고 현재 위치값을 포함한 값 중 큰 값을 고름
					dp[i][j] = max(dp[i - 2][j] + arr[i - 1][j - 1], dp[i - 1][j - 1]);
					break;
				}
				if (maxValue < dp[i][j])
					maxValue = dp[i][j];
			}
		}

		return maxValue;
	}
}

//int main()
//{
//	vector<vector<int>> arr =
//	{
//		{1,7,13,2,6},
//		{2,-4,2,5,4},
//		{5,3,5,-3,1},
//	};
//
//    int result = P72::solution(arr);
//
//        cout << result << " ";
//}
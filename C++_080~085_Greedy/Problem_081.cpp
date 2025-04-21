/// <summary>
/// 저자 출제
/// 부분 배낭 문제
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace P81
{
	double solution(vector<vector<int>> items, double weight_limit)
	{
		double answer = 0;
		sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b)
			{
				double aResult = (double)a[1] / (double)a[0];
				double bResult = (double)b[1] / (double)b[0];
				return aResult > bResult;
			});

		for (int i = 0; i < items.size(); i++)
		{
			if (weight_limit == 0) break;

			if (weight_limit >= items[i][0])
			{
				answer += items[i][1];
				weight_limit -= items[i][0];
			}
			else
			{
				double valuePerWeight = (double)items[i][1] / (double)items[i][0];
				answer += valuePerWeight * weight_limit;
				weight_limit = 0;
			}
		}

		return answer;
	}
}

//int main()
//{
//	vector<vector<int>> items = 
//	{
//		{10, 19},
//		{7, 10},
//		{6, 10},
//	};
//	double weight_limit = 15;
//
//    double result = P81::solution(items, weight_limit);
//
//        cout << result << " ";
//}
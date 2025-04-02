#include "Problem_001.h"

/// <summary>
/// 배열 정렬하기
/// 
/// 배열 오름차순으로 정렬
/// 
/// 제약조건
/// 1. arr 길이 : 2 ~ 10^5
/// 2. 원소값 : -100000 ~ 100000
/// </summary>
/// 
namespace Problem_001
{
	void ArrSorter::Sort(vector<int> arr)
	{
		sort(arr.begin(), arr.end());
		result = arr;
	}

	void ArrSorter::Debug()
	{
		for (int i : result)
		{
			cout << i << " ";
		}
	}

	vector<int> solution(vector<int> arr)
	{
		vector<int> answer;
		ArrSorter arraySorter;
		arraySorter.Sort(arr);
		arraySorter.Debug();

		answer = arraySorter.result;
		return answer;
	}
}
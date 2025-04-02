#include "Problem_001.h"

/// <summary>
/// �迭 �����ϱ�
/// 
/// �迭 ������������ ����
/// 
/// ��������
/// 1. arr ���� : 2 ~ 10^5
/// 2. ���Ұ� : -100000 ~ 100000
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
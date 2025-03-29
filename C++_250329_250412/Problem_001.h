#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace Problem_001
{
	class ArrSorter
	{
	public:
		vector<int> result;

		void Sort(vector<int> arr);
		void Debug();
	};
	vector<int> solution(vector<int> arr);
}
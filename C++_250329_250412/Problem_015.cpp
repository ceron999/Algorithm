/// <summary>
/// 저자 출제
/// 여세푸스 문제
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>
// 저자 풀이
#include <unordered_map>

using namespace std;
namespace P15
{
	int solution(int N, int K) {
		int answer = -1;
		queue<int> table;

		for (int i =1; i<= N; i++)
		{
			table.push(i);
		}
		
		int count = 1;
		while (table.size() != 1)
		{
			if (count == 2)
			{
				table.pop();
				count = 1;
			}
			
			table.push(table.front());
			table.pop();
			count++;
		}

		answer = table.front();

		return answer;
	}
}
//
//int main()
//{
//	cout << P15::solution(5,2);
//}
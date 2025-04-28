/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/86051
/// 없는 숫자 더하기
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P91
{
	int solution(vector<int> numbers) {
		int answer = 45;

		for (int i : numbers)
		{
			answer -= i;
		}

		return answer;
	}
}

//int main()
//{
//	int result = P91::solution({ 1,2,3,4,6,7,8,0 });
//
//		cout << result << " ";
//}
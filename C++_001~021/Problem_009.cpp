/// <summary>
/// 저자 출제
/// 10 -> 2진수
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>

using namespace std;
namespace P9
{

	string solution(int decimal)
	{
		string answer ="";
		stack<int> stack;

		int nowDecimal = decimal;
		while (nowDecimal != 0)
		{
			stack.push(nowDecimal % 2);
			nowDecimal /= 2;
		}

		while (!stack.empty())
		{
			int num = stack.top();
			answer += to_string(num);
			stack.pop();
		}
		reverse(answer.begin(), answer.end());
		return answer;
	}
}
//int main()
//{
//	cout<<P9::solution(12345);
//}
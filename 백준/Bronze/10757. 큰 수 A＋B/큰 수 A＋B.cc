#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/* Baekjoon No.10757
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.*/

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num1, num2;
	int num1Size, num2Size;
	int max, min;
	int temp;
	int* sumArr = new int[10001];

	cin >> num1 >> num2;

	num1Size = num1.size();
	num2Size = num2.size();

	if (num1Size > num2Size)
	{
		max = num1Size;
		min = num2Size;
	}
	else
	{
		max = num2Size;
		min = num1Size;
	}

	for (int i = 10000; i > 10000 - min; i--)
	{
		temp = (int)num1.back() + (int)num2.back();
		sumArr[i] = temp - 96;	//char to int 할 경우 ascii에 의해 48이 더해져 형변환이 되므로 해당 값 빼주는 용도
		num1.pop_back();
		num2.pop_back();
	}

	for (int i = 10000 - min; i > 10000 - max; i--)
	{
		if (num1Size > num2Size)
		{
			sumArr[i] = (int)num1.back() - 48;
			num1.pop_back();
		}
		else
		{
			sumArr[i] = (int)num2.back() - 48;
			num2.pop_back();
		}
	}

	for (int i = 10000; i > 10000 - max + 1; i--)
	{
		if (sumArr[i] >= 10)
		{
			sumArr[i] %= 10;
			sumArr[i - 1]++;
		}
	}

	for (int i = 10000 - max + 1; i <= 10000; i++)
		cout << sumArr[i];
		
	return 0;
}
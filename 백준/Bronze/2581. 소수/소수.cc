#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/* Baekjoon No.1978
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.*/

bool IsPrimeNum(int getNum);

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int left, right;
	int min = 10001;
	int sum = 0;

	cin >> left >> right;
		
	for (int i = left; i <= right; i++)
	{
		if (IsPrimeNum(i))
		{
			sum += i;
			if (i < min) min = i;
		}
	}

	if (sum != 0)
		cout << sum << "\n" << min;
	else
		cout << "-1";
	
	return 0;
}

bool IsPrimeNum(int getNum)
{
	int numSqrt = sqrt(getNum);

	if (getNum == 1) return false;
	for (int i = numSqrt; i > 1; i--)
	{
		if (getNum % i == 0) return false;
	}

	return true;
}
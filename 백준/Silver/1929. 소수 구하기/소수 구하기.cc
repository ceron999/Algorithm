#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/* Baekjoon No.1929
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.*/

bool IsPrimeNum(int getNum);

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int left, right;
	int min = 1000001;
	int sum = 0;

	cin >> left >> right;

	for (int i = left; i <= right; i++)
	{
		if (IsPrimeNum(i))
		{
			cout << i << "\n";
		}
	}

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
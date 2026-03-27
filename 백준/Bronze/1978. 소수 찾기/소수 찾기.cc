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

	int n;
	int count = 0;
	int* numArr;

	cin >> n;

	numArr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> numArr[i];
		
	for (int i = 0; i < n; i++)
	{
		if (IsPrimeNum(numArr[i]))
			count++;
	}

	cout << count;
	
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
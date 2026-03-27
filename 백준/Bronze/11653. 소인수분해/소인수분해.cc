#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/* Baekjoon No.11653
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.*/

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	int i;

	cin >> num;

	int numSqrt = sqrt(num);

	for (i = 2; i <=numSqrt; i++)
	{
		while (num % i == 0)
		{
			cout << i << "\n";
			num /= i;
		}
		numSqrt = sqrt(num);
	}

	if (num > 1)
		cout << num;

	return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

/* Baekjoon No.4948
베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 
2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.
이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.
예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다. (11, 13, 17, 19) 또, 14보다 크고, 
28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)
자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오. */

void eratosthenes(bool getPrimeArr[]);

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int cnt = 0;

	vector<int> cntVec;
	int cntVecSize;

	bool prime[250000];
	memset(prime, false, 250000);
	
	eratosthenes(prime);

	do
	{
		cin >> n;

		for (int i = n + 1; i <= 2 * n; i++)
			if (prime[i]) cnt++;
		
		cntVec.push_back(cnt);
		
		cnt = 0;
	} while (n != 0);

	cntVecSize = cntVec.size();
	for (int i = 0; i < cntVecSize - 1; i++)
		cout << cntVec.at(i) << "\n";

	return 0;
}

void eratosthenes(bool getPrimeArr[])
{
	getPrimeArr[2] = true;

	// 홀수 전부 소수라고 간주
	for (int i = 3; i < 250000; i += 2)
		getPrimeArr[i] = true;


	for (int i = 3;; i += 2)
	{
		int j = i * i;
		if (j >= 250000) break;
		
		for (i *= 2; j < 250000; j += i)
			getPrimeArr[j] = false;

		i /= 2;
	}
}
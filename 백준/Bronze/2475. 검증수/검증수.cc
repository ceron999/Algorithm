#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int a, b, c, d, e;

int main()
{
	cin >> a >> b >> c >> d >> e;

	int num = a * a + b * b + c * c + d * d + e * e;

	cout << num % 10;
}
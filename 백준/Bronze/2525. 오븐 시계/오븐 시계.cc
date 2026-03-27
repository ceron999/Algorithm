#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	b = b + c;

	a = a + b / 60;
	if (a >= 24) a -= 24;
	b = b % 60;
	cout << a << " " << b << "\n";
}

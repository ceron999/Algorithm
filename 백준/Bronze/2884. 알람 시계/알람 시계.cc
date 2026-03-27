#include <iostream>

using namespace std;

int main()
{
	int H,M;
	cin >> H>>M;

	if (M - 45 < 0)
	{
		M = 15 + M;
		if (H - 1 < 0)
			cout << 23 + H << " " << M;
		else  cout << H - 1 << " " << M;
	}
	else
	{
		cout << H << " " << M - 45;
	}
}
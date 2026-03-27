#include <iostream>

using namespace std;

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int getN;
	cin >> getN;

	if(getN>0)
		for (int i = 1; i <= getN; i++)
		{
			cout << i << "\n";
		}

	return 0;
}

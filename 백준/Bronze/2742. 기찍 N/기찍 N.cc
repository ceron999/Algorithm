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
		for (int i = getN; i >= 1; i--)
		{
			cout << i << "\n";
		}

	return 0;
}

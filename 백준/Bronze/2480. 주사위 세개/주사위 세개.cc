#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;

int num1, num2, num3;
int ret = 0;

int main()
{
	cin >> num1 >> num2 >> num3;

	vector<int> sortingVec;
	sortingVec.push_back(num1);
	sortingVec.push_back(num2);
	sortingVec.push_back(num3);

	sort(sortingVec.begin(), sortingVec.end());

	if (sortingVec[0] < sortingVec[1] && sortingVec[1] < sortingVec[2])
	{
		ret = sortingVec[2] * 100;
	}
	else if (sortingVec[0] == sortingVec[1] && sortingVec[1] == sortingVec[2])
	{
		ret = 10000 + num1 * 1000;
	}
	else
	{
		ret = 1000 + sortingVec[1] * 100;
	}

	cout << ret;
}
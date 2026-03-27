#include <iostream>
#include <vector>

using namespace std;

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size;
	cin >> size;
	cin.ignore();

	char* nums = new char[size + 1];

	cin.getline(nums, size+1);

	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += ((int)nums[i] - 48);
	}

	cout << sum;

	return 0;
}
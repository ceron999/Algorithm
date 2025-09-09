#include<iostream>

using namespace std;

string input;

int main()
{
	cin >> input;

	int left = 0;
	int right = input.size() - 1;
	bool isRight = true;

	while (left <= right)
	{
		if (input[left] != input[right])
		{
			isRight = false;
			break;
		}
		left++;
		right--;
	}

	cout << isRight ? 1 : 0;

	return 0;
}
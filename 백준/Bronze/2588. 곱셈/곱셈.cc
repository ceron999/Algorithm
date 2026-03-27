#include <iostream>

using namespace std;

int main()
{
	int A, B;
	int get_B;
	int count = 0;

	cin >> A >> B;
	get_B = B;

	for (int i = 0; get_B >= 1; i++)
	{
		count++;
		get_B /= 10;
	}

	get_B = B;
	int* save_Arr = new int[count];
	int* decade_Arr = new int[count];
	decade_Arr[0] = 1;

	for (int i = 0; i < count; i++)
	{
		get_B = B % 10;
		cout << (save_Arr[i] = A * get_B) << endl;
		if (i != 0)
			decade_Arr[i] = decade_Arr[i-1] * 10;
		B /= 10;
	}

	int sum = 0;

	for (int i = 0; i < count; i++)
	{
		sum += save_Arr[i] * decade_Arr[i];
	}

	cout << sum;
	return 0;
}
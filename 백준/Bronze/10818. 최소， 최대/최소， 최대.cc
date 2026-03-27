#include <iostream>

using namespace std;

class list
{
public:
	void Select(int* getArr, int size)
	{
		int min, max;
		min = max = getArr[0];
		for (int i = 0; i < size; i++)
		{
			if (min > getArr[i])
				min = getArr[i];
			if (max < getArr[i])
				max = getArr[i];
		}

		cout << min << " " << max << "\n";
	}
private:
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;

	int arrSize;
	int* intArr;

	cin >> arrSize;

	intArr = new int[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		cin >> intArr[i];
	}

	list1.Select(intArr, arrSize);

	delete[] intArr;
	
	return 0;
}
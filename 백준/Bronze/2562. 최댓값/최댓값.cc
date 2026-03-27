#include <iostream>

using namespace std;

class list
{
public:
	void Select(int* getArr, int size)
	{
		int max;
		max = getArr[0];
		for (int i = 0; i < size; i++)
		{
			if (max < getArr[i])
			{
				max = getArr[i];
				count = i + 1;
			}
		}

		cout << max << "\n" << count;
	}
private:
	int count = 1;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;

	int arrSize = 9;
	int* intArr;

	intArr = new int[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		cin >> intArr[i];
	}

	list1.Select(intArr, arrSize);

	delete[] intArr;
	
	return 0;
}
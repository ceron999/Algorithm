#include <iostream>

using namespace std;

class arr
{
public:
	void GetInt()
	{
		cin >> testCase;
		cin >> pivot;
		if (testCase <= 0)
			GetInt();
	}

	void GetIntArr()
	{
		if (testCase > 0)
		{
			intArr = new int[testCase];
			for (int i = 0; i < testCase; i++)
			{
				cin >> intArr[i];
			}
		}
		else exit(1);
	}

	void PrintNum()
	{
		if (intArr != NULL)
		{
			for (int i = 0; i < testCase; i++)
			{
				if (intArr[i] < pivot)
					cout << intArr[i] << " ";
			}
		}
		else exit(1);
	}
	~arr()
	{
		if(intArr != NULL)
			delete[] intArr;
	}
private:
	int testCase;
	int pivot;
	int* intArr;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr arr1;
	arr1.GetInt();
	arr1.GetIntArr();
	arr1.PrintNum();

	return 0;
}
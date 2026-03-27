#include <iostream>

using namespace std;

class list
{
public:
	list()	
	{
		getIntArr = new int[10];
		remainderArr = new int[11];
	}

	void GetInt()
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> getIntArr[i];
			remainderArr[i+1] = getIntArr[i] % 42;
		}
	}

	void Insert(int e, int* getArr, int i)
	{
		getArr[0] = e;

		while (e < getArr[i])
		{
			getArr[i + 1] = getArr[i];
			i--;
		}
		getArr[i + 1] = e;
	}

	void InsertionSort()
	{
		for (int j = 2; j <= 10; j++)
		{
			int temp = remainderArr[j];
			Insert(temp, remainderArr, j - 1);
		}
	}

	void Count()
	{
		int count = 1;

		for (int i = 1; i < 10; i++)
		{
			int currNum = remainderArr[i];

			if (currNum != remainderArr[i + 1])
				count++;
		}

		cout << count;
	}

	void Print()
	{
		for (int i = 1; i <= 10; i++)
		{
			cout << remainderArr[i] << " ";
		}
	}

	~list()
	{
		delete[] getIntArr;
		delete[] remainderArr;
	}

private:
	int* getIntArr;
	int* remainderArr;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;
	list1.GetInt();
	list1.InsertionSort();
	list1.Count();

	return 0;
}
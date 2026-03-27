#include <iostream>
#include <vector>

using namespace std;

class list
{
public:
	list(int getNum)
	{
		num = getNum;
		if (num < 99)
			count = num;
		else
			count = 99;
	}

	bool IsHan(int getNum)
	{
		int temp = getNum;
		int size = 0;
		while (temp > 0.1)
		{
			size++;
			temp /= 10;
		}
		int* arr = new int[size];

		for (int i = size-1; i >= 0; i--)
		{
			arr[i] = getNum % 10;
			getNum /= 10;
		}

		bool isHan = true;
		int d = arr[1] - arr[0];

		for (int i = 1; i < size; i++)
		{
			if (arr[i] != arr[i - 1] + d)
				isHan = false;
		}

		if (isHan)
		{
			delete[] arr;
			return true;
		}
		else
		{
			delete[] arr;
			return false;
		}
	}

	void GetCount()
	{
		if (num > 110)
		{
			for (int i = 111; i <= num; i++)
			{
				if (IsHan(i))
					count++;
			}

		}

		cout << count;
	}

	~list()
	{
		
	}

private:
	int num;
	int count;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int getNum;
	cin >> getNum;

	list list1(getNum);
	list1.GetCount();

	return 0;
}
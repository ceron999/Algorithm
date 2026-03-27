#include <iostream>
#include <vector>

using namespace std;

class list
{
public:
	list()
	{
		arr = new int[10001];

		for (int i = 1; i <= 10000; i++)
			arr[i] = i;
	}

	int D(int n)
	{
		int sum = n;
		int* nArr = new int[5];

		for (int i = 0; n > 0.1; i++)
		{
			nArr[i] = n % 10;
			n /= 10;

			sum += nArr[i];
		}

		return sum;
	}

	void DeleteNum()
	{
		for (int i = 1; i <= 10000; i++)
		{
			if (D(i) <= 10000)
				arr[D(i)] = 0;
		}
	}

	void PrintNum()
	{
		for (int i = 1; i <= 10000; i++)
		{
			if (arr[i] != 0)
				cout << arr[i] << "\n";
		}
	}

	~list()
	{
		delete[] arr;
	}

private:
	int* arr;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;
	list1.DeleteNum();
	list1.PrintNum();

	return 0;
}
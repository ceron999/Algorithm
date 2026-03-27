#include <iostream>
#include <vector>
#include <string>

using namespace std;

class list
{
public:
	list(int getNum1, int getNum2)
	{
		num1 = getNum1;
		num2 = getNum2;
	}

	void ReverseNum()
	{
		int* tempArr = new int[3];

		for (int i=0;num1 > 0.1;i++)
		{
			tempArr[i] = num1 % 10;
			num1 /= 10;
		}

		num1 = tempArr[0] * 100 + tempArr[1] * 10 + tempArr[2];

		for (int i = 0; num2 > 0.1; i++)
		{
			tempArr[i] = num2 % 10;
			num2 /= 10;
		}

		num2 = tempArr[0] * 100 + tempArr[1] * 10 + tempArr[2];
	}

	void PrintNum()
	{
		if (num1 > num2)
			cout << num1;
		else
			cout << num2;
	}

	~list()
	{
		
	}

private:
	int num1;
	int num2;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int getNum1, getNum2;
	cin >> getNum1;
	cin >> getNum2;

	list list1(getNum1, getNum2);
	list1.ReverseNum();
	list1.PrintNum();

	return 0;
}
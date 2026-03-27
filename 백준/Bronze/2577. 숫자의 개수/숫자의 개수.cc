#include <iostream>

using namespace std;

class list
{
public:
	list(int getNum1, int getNum2, int getNum3)
		: num1(getNum1), num2(getNum2), num3(getNum3),
		  mul(getNum1* getNum2* getNum3), arrSize(0), arr(0)
	{
		for (int i = 0; i < 10; i++)
		{
			count[i] = 0;
		}
	}

	void SetArr()
	{
		int i = 0;
		int temp = mul;
		int* tempArr = new int[9];
		
		for (;temp>0.1;)
		{
			tempArr[i] = temp % 10;
			temp /= 10;
			i++;
		}

		arrSize = i;
		arr = new int[arrSize];

		for (int j = 0; j < arrSize; j++)
		{
			arr[j] = tempArr[j];
		}

		delete[]tempArr;
	}

	void CountNum()
	{
		for (int i = 0; i < arrSize; i++)
		{
			switch (arr[i])
			{
			case 0:
				count[0] = count[0] + 1;
				break;
			case 1:
				count[1] = count[1] + 1;
				break;
			case 2:
				count[2] = count[2] + 1;
				break;
			case 3:
				count[3] = count[3] + 1;
				break;
			case 4:
				count[4] = count[4] + 1;
				break;
			case 5:
				count[5] = count[5] + 1;
				break;
			case 6:
				count[6] = count[6] + 1;
				break;
			case 7:
				count[7] = count[7] + 1;
				break;
			case 8:
				count[8] = count[8] + 1;
				break;
			case 9:
				count[9] = count[9] + 1;
				break;
			}
		}
	}

	void Print()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << count[i] << "\n";
		}
	}

	~list()
	{
		if (!arr)
		{
			delete[] arr;
		}
	}

private:
	int num1, num2, num3;
	int mul;
	int arrSize;
	int* arr;
	int* count = new int[10];
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int getNum1, getNum2, getNum3;

	cin >> getNum1;
	cin >> getNum2;
	cin >> getNum3;

	list list1(getNum1, getNum2, getNum3);
	list1.SetArr();
	list1.CountNum();
	list1.Print();

	return 0;
}
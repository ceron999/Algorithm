#include <iostream>

using namespace std;

class getInt
{
public:
	getInt();
	void GetTestCase();
	void GetIntArr();
	void Sum();
	void PrintSum();
	~getInt();
private:
	int testCase;
	int* getInt1;
	int* getInt2;
	int* sum;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getInt getIntClass;

	getIntClass.GetTestCase();
	getIntClass.GetIntArr();
	getIntClass.Sum();
	getIntClass.PrintSum();

	return 0;
}

getInt::getInt()
{
	int testCase = 0;
	int* getInt1 = NULL;
	int* getInt2 = NULL;
	int* sum = NULL;
}

void getInt::GetTestCase()
{
	cin >> testCase;
	if (testCase <= 0)
	{
		testCase = 0;
		GetTestCase();
	}
}

void getInt::GetIntArr()
{
	if (testCase > 0)
	{
		getInt1 = new int[testCase];
		getInt2 = new int[testCase];

		for (int i = 0; i < testCase; i++)
		{
			cin >> getInt1[i];
			cin >> getInt2[i];
		}
	}
	else
	{
		GetTestCase();
		GetIntArr();
	}
}

void getInt::Sum()
{
	if (testCase > 0)
	{
		sum = new int[testCase];

		for (int i = 0; i < testCase; i++)
		{
			sum[i] = getInt1[i] + getInt2[i];
		}
	}
}

void getInt::PrintSum()
{
	if (testCase > 0)
	{
		for (int i = 0; i < testCase; i++)
		{
			cout << "Case #" << i + 1 << ": " 
				<<getInt1[i] << " + "<< getInt2[i] << " = " << sum[i] << "\n";
		}
	}
}

getInt::~getInt()
{
	delete[] getInt1;
	delete[] getInt2;
	delete[] sum;
}
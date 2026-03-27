#include <iostream>
#include <vector>
#include <string>

using namespace std;

class list
{
public:
	list(int getTestCase)
	{
		testCase = getTestCase;
		count = new int[testCase];
		str = new string[testCase];
	}

	void GetCountStr()
	{
		for (int i = 0; i < testCase; i++)
		{
			cin >> count[i];
			cin >> str[i];
		}
	}

	void Print()
	{
		for (int i = 0; i < testCase; i++)
		{
			//개별 테스트케이스 프린트
			for (int strIdx=0;strIdx < str[i].size();strIdx++)
			{
				for (int cnt = 0; cnt < count[i]; cnt++)
					cout << str[i][strIdx];
			}
			cout << "\n";
		}
	}

	~list()
	{
		delete[] str;
	}

private:
	int testCase;
	int* count;
	string* str;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	list list1(testCase);
	list1.GetCountStr();
	list1.Print();

	return 0;
}
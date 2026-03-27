#include <iostream>

using namespace std;

class list
{
public:
	list()
		:arrSize(0)
	{	
		result = nullptr;
	}

	void GetCharArr()
	{
		char* tempArr = new char[80];
		char ch;

		for (int i = 0; (ch= cin.get()) != '\n'; i++)
		{
			arrSize++;
			tempArr[i] = ch;
		}

		result = new char[arrSize];
		
		for (int i = 0; i < arrSize; i++)
		{
			result[i] = tempArr[i];
		}

		delete[] tempArr;
	}

	void GetPoint()
	{
		for (int i = 0; i < arrSize; i++)
		{
			if (result[i] == 'O')
			{
				sum += point;
				point++;
			}

			else
				point = 1;
			
		}
	}

	void PrintSum()
	{
		cout << sum << "\n";
	}

	~list()
	{
		delete[] result;
	}

private:
	int arrSize;	//생성된 배열의 크기
	char* result;	//ox를 담을 배열
	int sum = 0;	//총점
	int point = 1;	//획득할 수 있는 점수
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	list* listArr = new list[testCase];

	cin.ignore();

	for (int i = 0; i < testCase; i++)
	{
		listArr[i].GetCharArr();
		listArr[i].GetPoint();
	}

	for (int i = 0; i < testCase; i++)
	{
		listArr[i].PrintSum();
	}

	return 0;
}
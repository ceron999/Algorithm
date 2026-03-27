#include <iostream>
#include <vector>
#include <string>

using namespace std;

class list
{
public:
	list()
	{
		cin >> str;

		numArr = new int[str.size()];
		time = 0;
	}


	void TransformStr2Num()
	{
		int temp;
		for (int i = 0; i < str.size(); i++)
		{
			//(해당 알파벳의 아스키 코드 - 65) / 3한 몫에 +2를 더해 다이얼 숫자 맞추기
			temp = ((int)str[i] - 65) /3 + 2;


			//S부터 예외처리
			if (str[i] == 'S')
				temp = 7;
			else if (str[i] == 'V')
				temp = 8;
			else if (str[i] == 'Y')
				temp = 9;
			else if (str[i] == 'Z')
				temp = 9;

			numArr[i] = temp;
		}
	}

	void PrintTime()
	{
		for (int i = 0; i < str.size(); i++)
		{
			time += (numArr[i] + 1);
		}
		cout << time;
	}

	~list()
	{
		delete[] numArr;
	}

private:
	string str;
	int time;
	int* numArr;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;
	list1.TransformStr2Num();
	list1.PrintTime();

	return 0;
}
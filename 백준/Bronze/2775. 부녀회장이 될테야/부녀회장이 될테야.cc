#include <iostream>
#include <vector>

using namespace std;

class list
{
public:
	list()
	{
		cin >> k;
		cin >> h;
		num = 0;
	}

	int GetNum(int roomK,int roomH)
	{
		int result = 0;

		if (roomK == 0)
		{
			return roomH;
		}

		if (roomH == 1) return 1;
		else
		{
			for (int i = 1; i <= roomH; i++)
				result += GetNum(roomK - 1, i);
		}

		return result;
	}

	void PrintNum()
	{
		num = GetNum(k, h);
		cout << num << "\n";
	}

	~list()
	{

	}

private:
	int k;
	int h;
	int num;
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

	for (int i = 0; i < testCase; i++)
	{
		listArr[i].PrintNum();
	}

	delete[] listArr;
	return 0;
}
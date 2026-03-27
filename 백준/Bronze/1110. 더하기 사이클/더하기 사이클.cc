#include <iostream>

using namespace std;

class cycle
{
public:
	cycle(int getNum)
		:cycleCount(0), firstNum(getNum)
	{}

	void DoCycle()
	{
		int nextNum = 0;
		int getNum = firstNum;

		int digit;
		int remainder;
		int sum;

		do
		{
			if (getNum < 10)
			{
				nextNum = getNum * 11;
				getNum = nextNum;
			}
			else
			{
				digit = getNum / 10;
				remainder = getNum % 10;

				sum = digit + remainder;

				nextNum = remainder * 10 + sum % 10;
				getNum = nextNum;
			}
			cycleCount++;
		} while (nextNum != firstNum);

		cout << cycleCount << "\n";
	}

private:
	int cycleCount;
	int firstNum;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	cycle a(num);
	a.DoCycle();

	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class list
{
public:
	list()
	{
		cin >> fixedCost;
		cin >> variableExp;
		cin >> price;
		count = 0;
	}

	void GetBreakEvenPoint()
	{
		if (price > variableExp)
		{
			count = fixedCost / (price - variableExp);

			if (count < 0)
				count = -1;
			else
				count++;
		}
		else
			count = -1;

		cout << count;
	}

	~list()
	{

	}

private:
	int fixedCost;
	int variableExp;
	int price;
	int count;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;
	list1.GetBreakEvenPoint();

	return 0;
}
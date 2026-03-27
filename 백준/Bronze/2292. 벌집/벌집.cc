#include <iostream>
#include <vector>
#include <string>

using namespace std;

class list
{
public:
	list()
	{
		cin >> num;
		count = 0;
	}

	void GetGoal()
	{
		while (1)
		{
			if (num <= 3 * count * count + 3 * count + 1)
				break;
			count++;
		}

		cout << count + 1;
	}

	~list()
	{

	}

private:
	int num;
	int count;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;
	list1.GetGoal();

	return 0;
}
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
		row = 1;
		col = 1;
		line = 1;
	}

	void FindLocation()
	{
		int lineMax = line * (line + 1) / 2;
		//짝수 line
		if (line % 2 == 0)
		{
			for (int i = 0; i < line; i++)
			{
				if (num == lineMax) break;
				row--;
				col++;
				lineMax--;
			}
		}
		else
		{
			for (int i = 0; i < line; i++)
			{
				if (num == lineMax) break;
				row++;
				col--;
				lineMax--;
			}
		}
	}

	void FindLine()
	{
		while (1)
		{
			if (num <= line * (line + 1) / 2) break;
			line++;
		}

		if (line % 2 == 0)
			row = line;
		else
			col = line;
	}

	void Print()
	{
		cout << row << "/" << col;
	}

	~list()
	{

	}

private:
	int row;
	int col;
	int line;
	int num;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;
	list1.FindLine();
	list1.FindLocation();
	list1.Print();

	return 0;
}
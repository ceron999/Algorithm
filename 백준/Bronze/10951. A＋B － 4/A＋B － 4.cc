#include <iostream>

using namespace std;

class intNode
{
public:
	friend class intList;
	intNode(int getData1 = 0, int getData2 = 0, intNode* getlink = 0)
		:data1(getData1), data2(getData2), link(getlink)
	{}
	void PrintSum()
	{
		cout << data1 + data2 << "\n";
	}

private:
	int data1;
	int data2;
	intNode* link;
};

class intList
{
public:
	intList(intNode* getFirst = 0, intNode* getLast = 0)
	{
		first = getFirst;
		last = getLast;
	}

	void AddIntNode(int getData1, int getData2)
	{
		intNode* newNode = new intNode(getData1, getData2);

		if (!first)
		{
			first = last = newNode;
			first->link = newNode;
		}
		else
		{
			last->link = newNode;
			last = newNode;
		}
	}

	void PrintSum()
	{
		intNode* currNode = first;
		while (currNode != last->link)
		{
			cout << currNode->data1 + currNode->data2 << "\n";
			currNode = currNode->link;
		}
	}
private:
	intNode* first;
	intNode* last;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	intList intList1;

	char* intLine = new char[5];
	int getInt1, getInt2;

	while (1)
	{
		cin.getline(intLine,5);

		if (intLine[0] == '\0') break;

		getInt1 = (int)intLine[0] - 48;
		getInt2 = (int)intLine[2] - 48;

		intList1.AddIntNode(getInt1, getInt2);
	}

	intList1.PrintSum();

	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class strNode
{
public:
	friend class list;
	strNode(int getCount=0, char getChar=0)
	{
		count = getCount;
		ch = getChar;
	}
	void getInfo( char getChar)
	{
		ch = getChar;
	}

	void UpCount()
	{
		count++;
	}

	int ReturnCount()
	{
		return count;
	}

	char ReturnCh()
	{
		return ch;
	}
	
private:
	int count;
	char ch;
};

class list
{
public:
	list(string getStr)
	{
		str = getStr;
		char ch = 'A';

		for (int i = 0; i < 26; i++)
		{
			strArr[i].getInfo(ch);
			ch++;
		}
	}

	void GetCount()
	{
		int strIdx = 0;
		for (int i = 0; i < str.size(); i++)
		{
			strIdx = (int)str[i] - 65;
			if (strIdx >= 32)
				strIdx -= 32;

			strArr[strIdx].UpCount();
		}
	}

	void IsMost()
	{
		strNode mostNode, subNode;
		mostNode = strArr[0];
		for (int i = 1; i < 26; i++)
		{
			if (mostNode.ReturnCount() < strArr[i].ReturnCount())
				mostNode = strArr[i];

			else if (mostNode.ReturnCount() == strArr[i].ReturnCount())
				subNode = strArr[i];
		}

		if (mostNode.ReturnCount() == subNode.ReturnCount())
			cout << "?";
		else
			cout << mostNode.ReturnCh();
	}

	~list()
	{
		delete[] strArr;
	}

private:
	string str;
	strNode* strArr = new strNode[26];
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	list list1(str);
	list1.GetCount();
	list1.IsMost();

	return 0;
}
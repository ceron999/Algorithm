#include <iostream>
#include <vector>
#include <string>

using namespace std;

class list
{
public:
	list()
	{
		wordCount = 0;
		ch = 0;

		getline(cin,str,'\n');
		str.push_back('#');
	}

	void ReadWord()
	{
		int idx;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ')
			{
				if (str[i] == '#') break;
				idx = EndWord(i);
				i = idx;
			}
		}

		cout << wordCount;
	}

	int EndWord(int getIdx)
	{
		int returnNum = getIdx;

		for (; returnNum < str.size(); returnNum++)
		{
			if (str[returnNum] == ' '|| str[returnNum] =='#')
			{
				wordCount++;
				break;
			}
		}

		return returnNum;
	}

	~list()
	{
		
	}

private:
	int wordCount;
	string str;
	char ch;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;
	list1.ReadWord();

	return 0;
}
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

		getline(cin, str, '\n');
		str.push_back('#');
	}

	bool IsExeption(int getIdx)
	{
		if (str[getIdx] == 'c' && str[getIdx + 1] == '=')									return true;
		else if (str[getIdx] == 'c' && str[getIdx + 1] == '-')								return true;
		else if (str[getIdx] == 'd' && str[getIdx + 1] == 'z' && str[getIdx + 2] == '=')	return true;
		else if (str[getIdx] == 'd' && str[getIdx + 1] == '-')								return true;
		else if (str[getIdx] == 'l' && str[getIdx + 1] == 'j')								return true;
		else if (str[getIdx] == 'n' && str[getIdx + 1] == 'j')								return true;
		else if (str[getIdx] == 's' && str[getIdx + 1] == '=')								return true;
		else if (str[getIdx] == 'z' && str[getIdx + 1] == '=')								return true;
		else return false;
	}

	int ExeptionIdx(int getIdx)
	{
		if (str[getIdx] == 'c' && str[getIdx + 1] == '=')									return getIdx + 1;
		else if (str[getIdx] == 'c' && str[getIdx + 1] == '-')								return getIdx + 1;
		else if (str[getIdx] == 'd' && str[getIdx + 1] == 'z' && str[getIdx + 2] == '=')	return getIdx + 2;
		else if (str[getIdx] == 'd' && str[getIdx + 1] == '-')								return getIdx + 1;
		else if (str[getIdx] == 'l' && str[getIdx + 1] == 'j')								return getIdx + 1;
		else if (str[getIdx] == 'n' && str[getIdx + 1] == 'j')								return getIdx + 1;
		else if (str[getIdx] == 's' && str[getIdx + 1] == '=')								return getIdx + 1;
		else if (str[getIdx] == 'z' && str[getIdx + 1] == '=')								return getIdx + 1;
		else return getIdx;
	}

	void ReadWord()
	{
		int idx;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '#') break;
			if (IsExeption(i))
			{
				idx = ExeptionIdx(i);
				i = idx;
				wordCount++;
			}
			else
				wordCount++;
		}

		cout << wordCount;
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
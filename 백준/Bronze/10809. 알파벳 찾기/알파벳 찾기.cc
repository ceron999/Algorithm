#include <iostream>
#include <vector>
#include <string>

using namespace std;

class list
{
public:
	list()
	{
		for(int i =0; i<26; i++)
			location[i] = -1;
	}

	void GetString(string getStr)
	{
		for (int i = 0; i<getStr.size();i++)
		{
			int index = (int)getStr[i] - 97;

			if (location[index] == -1)
				location[index] = i;
		}
	}

	void PrintLocation()
	{
		for (int i = 0; i < 26; i++)
		{
			cout << location[i] << " ";
		}
	}

	~list()
	{
		delete[] location;
	}

private:
	int* location = new int[26];

};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1;
	cin >> str1;

	list list1;
	list1.GetString(str1);
	list1.PrintLocation();

	return 0;
}
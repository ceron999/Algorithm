#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

// 
int n;
string pattern;
string front, back;
vector<string> files;

int main()
{
	cin >> n >> pattern;

	int pos = pattern.find('*');
	front = pattern.substr(0, pos);
	back = pattern.substr(pos + 1);
	
	files.resize(n, "");
	for (int i = 0;i < n;i++)
	{
		cin >> files[i];
	}

	for (string file : files)
	{
		if (front.size() + back.size() > file.size())
		{
			cout << "NE\n";
			continue;
		}
		if (front == file.substr(0, front.size()) && back == file.substr(file.size() - back.size()))
		{
			cout << "DA\n";
		}
		else
			cout << "NE\n";
	}

	return 0;
}
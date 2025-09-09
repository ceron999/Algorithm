#include<iostream>
#include<string>

using namespace std;

char ROT13(char c)
{
	int result = c;
	if ('A' <= c && c <= 'Z')
	{
		result += 13;

		if (result > 'Z')
			result -= 26;
	}
	else if ('a' <= c && c <= 'z')
	{
		result += 13;

		if (result > 'z')
			result -= 26;
	}
	
	return (char)result;
}

int main()
{
	string input, result;
	getline(cin, input);

	for (int i = 0; i < input.size(); i++)
	{
		result += ROT13(input[i]);
	}

	cout << result;

	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

// 패스워드 만들기
// 1. 모음 하나 반드시 포함
// 2. 모음이나 자음이 3개 연속 x
// 3. 같은 글자 연속 x (ee, oo 가능)

string input;

bool IsVowel(const char& c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else return false;
}

bool isAcceptable(const string& password)
{
	bool isContainVowel = false;
	int vowel = 0;
	int consonant = 0;

	for (int i =0; i< password.size(); i++)
	{
		// 같은글자 연속 제거
		if (i > 0 && (password[i] == password[i - 1]))
		{
			if (password[i] != 'e' && password[i] != 'o')
				return false;
		}

		if (IsVowel(password[i]))
		{
			isContainVowel = true;
			vowel++;
			consonant = 0;

			// 모음이나 자음이 3회 이상이면 탈락
			if (vowel >= 3) return false;
		}
		else
		{
			vowel = 0;
			consonant++;

			// 모음이나 자음이 3회 이상이면 탈락
			if (consonant >= 3) return false;
		}
	}

	if (!isContainVowel) 
		return false;
	else
		return true;
}

int main()
{
	while (cin >> input)
	{
		if (input == "end")break;

		if (isAcceptable(input))
		{
			cout << "<" << input << "> is acceptable.\n";
		}
		else
			cout << "<" << input << "> is not acceptable.\n";
	}
}
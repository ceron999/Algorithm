#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

// n개의 포켓몬개수 , 맞춰야할 문제 개수 m
// 2~n+1까지 포켓몬 이름(첫 글자 대문자 or 마지막 글자만 대문자)
// 그 다음 줄부터 m개의 줄에 내가 맞춰야할 문제 들어옴  - 알파벳은 번호 번호는 알파벳
// 번호는 1~n으로 들어옴 0은 무시해야함
int n, m;

int main()
{
	map<string, int> poketmonStringMap;
	map<int, string> poketmonMap;
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;

		poketmonStringMap[name] = i;
		poketmonMap[i] = name;
	}


	vector<string> questions;
	questions.resize(m, "");
	for (int i = 0;i < m;i++)
	{
		cin >> questions[i];
	}

	for (int i = 0;i < m;i++)
	{
		if (questions[i][0] < 'A')
		{
			int num = stoi(questions[i]);
			cout << poketmonMap[num] << "\n";
		}
		else
		{
			cout << poketmonStringMap[questions[i]] << "\n";
		}
	}
	
	return 0;
}
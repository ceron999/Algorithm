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
map<stirng, int> mp;
map<int, string> mp2;
string a[100004];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n;i++)
	{
		cin >> s;
		mp[s] = i + 1;
		mp2[i+1] = s;
		a[i + 1] = s;
	}

	for (int i = 0;i < m;i++)
	{
		cin >> s;
		if (atoi(s.c_str()) == 0)
		{
			cout << mp[s] << "\n";
		}
		else
		{
			cout << a[atoi(s.c_str())] << "\n";
		}
	}
	
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int n;
int a = 0, b = 0, atIme = 0, btime = 0;
int last = 0;

int parseStrToInt(string& time)
{
	string m = time.substr(0, 2);
	string s = time.substr(3);
	return atoi(m.c_str()) * 60 + atoi(s.c_str());
}

string parseIntToStr(int& time)
{
	string min = "00" + to_string(time / 60);
	string sec = "00" + to_string(time % 60);

	return min.substr(min.size() - 2) + ":" + sec.substr(sec.size() - 2);
}

int main()
{
	cin >> n;

	while (n--)
	{
		int team;
		string t;
		cin >> team >> t;

		int currTime = parseStrToInt(t);

		if (a > b)
		{
			atIme += currTime - last;
		}
		else if(a < b)
		{
			btime += currTime - last;
		}
		last = currTime;

		team == 1 ? a++ : b++;
	}
	if (a > b)
	{
		atIme += 48 * 60 - last;
	}
	else if (a < b)
	{
		btime += 48 * 60 - last;
	}

	cout << parseIntToStr(atIme) << endl;
	cout << parseIntToStr(btime) << endl;
}
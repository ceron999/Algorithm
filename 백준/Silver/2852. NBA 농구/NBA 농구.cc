#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, aTime = 0, bTime = 0, aScore = 0, bScore = 0, prevTime = 0;

int parseTImeStrToInt(string& time)
{
	int min = stoi(time.substr(0, 2));
	int sec = stoi(time.substr(3, 2));
	
	return min * 60 + sec;
}

string parseTimeToStr(int time)
{
	string result;

	int min = time / 60;
	int sec = time % 60;

	string minStr = "00" + to_string(min);
	string secStr = "00" + to_string(sec);

	result = minStr.substr(minStr.size() - 2) + ":" + secStr.substr(secStr.size() - 2);
	return result;
}

int main()
{
	cin >> n;

	while (n--)
	{
		int winTeam;
		int time;
		string timeStr;
		cin >> winTeam >> timeStr;

		time = parseTImeStrToInt(timeStr);
		
		if (aScore > bScore)
		{
			aTime += (time - prevTime);
		}
		else if (aScore < bScore)
		{
			bTime += (time - prevTime);
		}
		prevTime = time;
		winTeam == 1 ? aScore++ : bScore++;
	}

	if (aScore > bScore)
	{
		aTime += (48 * 60 - prevTime);
	}
	else if (aScore < bScore)
	{
		bTime += (48 * 60 - prevTime);
	}

	cout << parseTimeToStr(aTime) << "\n";
	cout << parseTimeToStr(bTime) << "\n";
}
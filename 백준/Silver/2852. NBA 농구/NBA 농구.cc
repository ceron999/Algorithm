#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int n, team1 = 0, team2 = 0;

pair<int, int> team1WinTime = { 0,0 };
pair<int, int> team2WinTime = { 0,0 };
pair<int, int> lastTime = { 0,0 };


pair<int, int> split(const string& input)
{
	vector<int> result;

	auto pos = input.find(':');

	string first, second;
	first = input.substr(0, pos);
	second = input.substr(pos + 1);

	int min = atoi(first.c_str());
	int sec = atoi(second.c_str());

	return { min, sec };
}

void UpdateTime(pair<int, int>& teamTime, pair<int, int> time)
{
	teamTime.first += time.first - lastTime.first;
	teamTime.second += time.second - lastTime.second;
	if (teamTime.second < 0)
	{
		teamTime.first--;
		teamTime.second += 60;
	}
	else if (teamTime.second >= 60)
	{
		teamTime.first++;
		teamTime.second -= 60;
	}
}

void Print(pair<int, int>& teamTime)
{
	string first, second;
	
	if (teamTime.first <10)
	{
		first = "0";
		first.push_back(teamTime.first + '0');
	}
	else
	{
		first = to_string(teamTime.first);
	}
	if (teamTime.second < 10)
	{
		second = "0";
		second.push_back(teamTime.second + '0');
	}
	else
	{
		second = to_string(teamTime.second);
	}
	cout << first << ":" << second << "\n";

}

int main()
{
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		int goalTeam;
		string timeStr;
		cin >> goalTeam >> timeStr;

		pair<int, int> time = split(timeStr);
		if (team1 > team2)
		{
			UpdateTime(team1WinTime, time);
			//cout << "\n임시 : " << team1WinTime.first << " : " << team1WinTime.second << "\n";
		}
		else if (team1 < team2)
		{
			UpdateTime(team2WinTime, time);
		}
		lastTime = time;

		if (goalTeam == 1) team1++;
		else team2++;
	}

	if (team1 > team2)
	{
		UpdateTime(team1WinTime, {48,0});
	}
	else if (team1 < team2)
	{
		UpdateTime(team2WinTime, { 48,0 });
	}
	Print(team1WinTime);
	Print(team2WinTime);
}
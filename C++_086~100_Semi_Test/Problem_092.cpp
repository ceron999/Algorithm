/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/64064
/// 불량 사용자
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
namespace P92
{
	vector<vector<string>> bannedList;
	bool IsSame(const string& a, const string& b)
	{
		if (a.size() != b.size())
			return false;

		for (int i = 0; i < a.size(); i++)
		{
			if (b[i] == '*')
				continue;

			if (a[i] != b[i])
				return false;
		}

		return true;
	}

	void dfs(unordered_map<int, vector<string>>& list, int now, vector<string> path)
	{
		if (now == list.size())
		{
			bannedList.push_back(path);
			return;
		}

		vector<string> curr = list[now];
		for (int row = 0; row < curr.size(); ++row)
		{
			vector<string> newPath = path;
			newPath.push_back(curr[row]);
			dfs(list, now + 1, newPath);
		}
	}

	int solution(vector<string> user_id, vector<string> banned_id) 
	{
		int answer = 1;
		unordered_map<int, vector<string>> bannedIdCount;
		for (int i =0; i< banned_id.size(); i++)
		{
			for (string nowUserId : user_id)
			{
				if (IsSame(nowUserId, banned_id[i]))
				{
					bannedIdCount[i].push_back(nowUserId);
				}
			}
		}
		
		vector<string> path;
		dfs(bannedIdCount, 0, path);

		for (int i = 0; i < bannedList.size(); i++)
		{
			unordered_set<string> curr;
			for (int j = 0; j < bannedList[0].size(); j++)
			{
				curr.insert(bannedList[i][j]);
			}

			if (curr.size() == bannedList[i].size())
				answer++;
		}

		return answer;
	}
}

int main()
{
	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = { "*rodo", "*rodo", "******" };
	int result = P92::solution(user_id, banned_id);

		cout << result << " ";
}
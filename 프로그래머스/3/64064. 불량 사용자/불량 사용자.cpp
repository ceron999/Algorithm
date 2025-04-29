#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

set<set<string>> bannedList;
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

void dfs(unordered_map<int, vector<string>>& list, int now, set<string> path)
{
	if (now == list.size())
	{
		if (path.size() != list.size())
			return;
		bannedList.insert(path);
		return;
	}

	vector<string> curr = list[now];
	for (int row = 0; row < curr.size(); ++row)
	{
		set<string> newPath = path;
		newPath.insert(curr[row]);
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
	
	set<string> path;
	dfs(bannedIdCount, 0, path);

	return bannedList.size();
}
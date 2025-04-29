/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/64064
/// 불량 사용자
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;
namespace P92
{
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

		return answer;
	}
}

namespace P92_Answer
{
	using namespace std;

	bool visited[1 << 8]; // 방문한 조합을 기록하는 배열

	// 깊이 우선 탐색(DFS)을 사용해 가능한 모든 경우의 수를 탐색합니다.
	void dfs(int banIdx, int totalBans, int bit, const vector<vector<int>>& candidates) {
		if (totalBans == banIdx) {
			visited[bit] = true; // 해당 조합을 방문했음을 표시
			return;
		}
		for (auto p : candidates[banIdx]) {
			if (bit & (1 << p)) continue; // 이미 선택된 사용자인 경우 건너뜁니다.
			dfs(banIdx + 1, totalBans, bit | (1 << p), candidates);
		}
	}

	// 불량 사용자 ID와 사용자 ID가 일치하는지 확인합니다.
	bool matches(const string& banned, const string& user) {
		if (banned.size() != user.size()) return false;
		for (int i = 0; i < banned.size(); i++) {
			if (!(banned[i] == user[i] || banned[i] == '*' || user[i] == '*')) {
				return false;
			}
		}
		return true;
	}

	int solution(vector<string> user_id, vector<string> banned_id) {
		int answer = 0;
		vector<vector<int>> candidates(banned_id.size());

		// 각 불량 사용자 ID에 대해 일치하는 사용자 ID의 인덱스를 저장합니다.
		for (int i = 0; i < banned_id.size(); i++) {
			for (int j = 0; j < user_id.size(); j++) {
				if (matches(banned_id[i], user_id[j])) {
					candidates[i].push_back(j);
				}
			}
		}

		dfs(0, banned_id.size(), 0, candidates);

		// 방문한 모든 조합을 계산합니다.
		for (int i = 0; i < (1 << 8); i++) {
			if (visited[i]) answer++;
		}

		return answer;
	}
}

//int main()
//{
//	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
//	vector<string> banned_id = { "*rodo", "*rodo", "******" };
//	int result = P92::solution(user_id, banned_id);
//
//		cout << result << " ";
//}
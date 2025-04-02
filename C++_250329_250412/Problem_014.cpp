/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/81303
/// 표 편집
/// 
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
#include <stdlib.h>
// 저자 풀이
#include <unordered_map>

using namespace std;
namespace P14
{
	// 변수 준비
	set<int> table;	//0~n-1을 담는 테이블
	set<int>::iterator nowNumIt;
	stack<int> deleteNumStack;

	void StartCmd(string nowCmd)
	{
		char firstChar = nowCmd[0];
		switch (firstChar)
		{
			// U x : 위로 x칸 이동
		case 'U':
		{
			int moveSize = stoi(nowCmd.substr(2));
			advance(nowNumIt, moveSize * -1);
		}
			break;
		case 'D':
		{
			int moveSize = stoi(nowCmd.substr(2));
			advance(nowNumIt, moveSize);
		}
			break;
		case 'C':
		{
			set<int>::iterator endIt = prev(table.end());
			
			if (endIt == nowNumIt)
			{
				deleteNumStack.push(*nowNumIt);
				table.erase(nowNumIt);
				nowNumIt = prev(table.end());
			}
			else
			{
				deleteNumStack.push(*nowNumIt);
				set<int>::iterator nextIt = next(nowNumIt);
				table.erase(nowNumIt);
				nowNumIt = nextIt;
			}
		}
			break;
		case 'Z':
		{
			if (deleteNumStack.size() > 0)
			{
				int recentNum = deleteNumStack.top();
				table.insert(recentNum);
				deleteNumStack.pop();
			}
		}
			break;
		default:
			cout << "이상한 command가 들어옴\n"<< nowCmd << endl;
			break;
		}
	}

	string solution(int n, int k, vector<string> cmd) {
		string answer = "";

		for (int i = 0; i < n; i++)
		{
			table.insert(i);
		}
		nowNumIt = table.find(k);


		for (string command : cmd)
		{
			 StartCmd(command);
		}

		int tableIdx = 0;
		for (int i = 0; i < n; i++)
		{
			if (table.find(i) == table.end() )
			{
				answer.push_back('x');
			}
			else
				answer.push_back('o');
		}
		cout << *nowNumIt << endl;
		return answer;
	}
}

namespace P14_2
{
	// 변수 준비
	list<int> table;
	list<int>::iterator nowNumIt;
	stack<pair<int, list<int>::iterator>> deleteNumStack;

	void StartCmd(string nowCmd)
	{
		char firstChar = nowCmd[0];
		switch (firstChar)
		{
			// U x : 위로 x칸 이동
		case 'U':
		{
			int moveSize = stoi(nowCmd.substr(2));
			advance(nowNumIt, -moveSize);
		}
		break;
		case 'D':
		{
			int moveSize = stoi(nowCmd.substr(2));
			advance(nowNumIt, moveSize);
		}
		break;
		case 'C':
		{
			int nowNum = *nowNumIt;
			auto nextIt = table.erase(nowNumIt);
			deleteNumStack.push({ nowNum, nextIt });

			if (nextIt == table.end())
			{
				nowNumIt = prev(table.end());
			}
			else
			{
				nowNumIt = nextIt;
			}
		}
		break;
		case 'Z':
		{
			if (deleteNumStack.size() > 0)
			{
				auto resentItPair = deleteNumStack.top();	//[삭제된 값, 삭제된 it 다음 it]
				deleteNumStack.pop();

				if (resentItPair.second == table.end())
				{
					table.push_back(resentItPair.first);
				}
				else
				{
					table.insert(resentItPair.second, resentItPair.first);  
				}
			}
		}
		break;
		default:
			cout << "이상한 command가 들어옴\n" << nowCmd << endl;
			break;
		}
	}
	namespace P14_SOlVED
	{
		string solution(int n, int k, vector<string> cmd) {

			// 삭제 된 행의 인덱스를 저장 
			stack<int> deleted;
			// 각 행의 위아래에 있는 행의 인덱스를 저장 
			vector<int> up;
			vector<int> down;

			for (int i = 0; i < n + 2; i++) {
				up.push_back(i - 1);
				down.push_back(i + 1);
			}
			// 임시공간을 고려한 현재위치 
			k++;

			// 주어진 명령어를 순회  
			for (int i = 0; i < cmd.size(); i++) {
				// 현재 위치를 삭제하고 그 다음 위치로 이동
				if (cmd[i][0] == 'C') {
					deleted.push(k);
					down[up[k]] = down[k];
					up[down[k]] = up[k];

					if (down[k] == n + 1) k = up[k];
					else k = down[k];
				}

				// 가장 최근에 삭제한 행을 복원
				else if (cmd[i][0] == 'Z') {
					int r = deleted.top();
					down[up[r]] = r;
					up[down[r]] = r;
					deleted.pop();
				}

				//  현재 행을 주어진 값 만큼 위혹은 아래로 이동
				else {
					int sz = stoi(cmd[i].substr(2));

					if (cmd[i][0] == 'U') {
						for (int j = 0; j < sz; j++) {
							k = up[k];
						}
					}

					else if (cmd[i][0] == 'D') {
						for (int j = 0; j < sz; j++) {
							k = down[k];
						}
					}
				}

			}

			string answer;

			// 삭제된 행의 위치에 “X”, 그렇지 않은 행의 위치에 “X” 로 표시한 문자열 반환
			answer.append(n, 'O');
			while (!deleted.empty()) {
				answer[deleted.top() - 1] = 'X';
				deleted.pop();
			}

			return answer;
		}
	}
	string solution(int n, int k, vector<string> cmd) {
		string answer = "";

		for (int i = 0; i < n; i++)
		{
			table.push_back(i);
		}
		nowNumIt = table.begin();
		advance(nowNumIt, k);

		for (string command : cmd)
		{
			StartCmd(command);
		}

		vector<char> result(n, 'X');
		for (int val : table) {
			result[val] = 'O';
		}
		answer =  string(result.begin(), result.end());
		
		return answer;
	}
}

//int main()
//{
//	cout << P14_2::solution(8,2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" });
//}
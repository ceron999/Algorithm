/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/81303
/// ǥ ����
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
// ���� Ǯ��
#include <unordered_map>

using namespace std;
namespace P14
{
	// ���� �غ�
	set<int> table;	//0~n-1�� ��� ���̺�
	set<int>::iterator nowNumIt;
	stack<int> deleteNumStack;

	void StartCmd(string nowCmd)
	{
		char firstChar = nowCmd[0];
		switch (firstChar)
		{
			// U x : ���� xĭ �̵�
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
			cout << "�̻��� command�� ����\n"<< nowCmd << endl;
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
	// ���� �غ�
	list<int> table;
	list<int>::iterator nowNumIt;
	stack<pair<int, list<int>::iterator>> deleteNumStack;

	void StartCmd(string nowCmd)
	{
		char firstChar = nowCmd[0];
		switch (firstChar)
		{
			// U x : ���� xĭ �̵�
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
				auto resentItPair = deleteNumStack.top();	//[������ ��, ������ it ���� it]
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
			cout << "�̻��� command�� ����\n" << nowCmd << endl;
			break;
		}
	}
	namespace P14_SOlVED
	{
		string solution(int n, int k, vector<string> cmd) {

			// ���� �� ���� �ε����� ���� 
			stack<int> deleted;
			// �� ���� ���Ʒ��� �ִ� ���� �ε����� ���� 
			vector<int> up;
			vector<int> down;

			for (int i = 0; i < n + 2; i++) {
				up.push_back(i - 1);
				down.push_back(i + 1);
			}
			// �ӽð����� ����� ������ġ 
			k++;

			// �־��� ��ɾ ��ȸ  
			for (int i = 0; i < cmd.size(); i++) {
				// ���� ��ġ�� �����ϰ� �� ���� ��ġ�� �̵�
				if (cmd[i][0] == 'C') {
					deleted.push(k);
					down[up[k]] = down[k];
					up[down[k]] = up[k];

					if (down[k] == n + 1) k = up[k];
					else k = down[k];
				}

				// ���� �ֱٿ� ������ ���� ����
				else if (cmd[i][0] == 'Z') {
					int r = deleted.top();
					down[up[r]] = r;
					up[down[r]] = r;
					deleted.pop();
				}

				//  ���� ���� �־��� �� ��ŭ ��Ȥ�� �Ʒ��� �̵�
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

			// ������ ���� ��ġ�� ��X��, �׷��� ���� ���� ��ġ�� ��X�� �� ǥ���� ���ڿ� ��ȯ
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
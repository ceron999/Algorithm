#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	vector<stack<int>> stackBoard(board.size());
	stack<int> pointStack;
	int nowStackPoint = 0;

	// 1. 스택에 마지막 배열부터 삽입
	for (int i = board.size() - 1; i >= 0; i--)
	{
		nowStackPoint = 0;
		for (int j = 0; j < board[0].size(); j++)
		{
			if(board[i][j] != 0)
				stackBoard[nowStackPoint].push(board[i][j]);
			nowStackPoint++;
		}
	}

	// 이제 뽑기 시작
	for (int stackIndex : moves)
	{
		if (!stackBoard[stackIndex - 1].empty())
		{
			// 포인트 획득
			if (!pointStack.empty() && pointStack.top() == stackBoard[stackIndex - 1].top())
			{
				answer += 2;
				pointStack.pop();
				stackBoard[stackIndex - 1].pop();
				continue;
			}
			pointStack.push(stackBoard[stackIndex - 1].top());
			stackBoard[stackIndex - 1].pop();
		}
	}

	cout << endl;
	return answer;
}
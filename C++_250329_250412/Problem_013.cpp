/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/64061
/// 크레인 인형뽑기
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

namespace P13
{
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
}


int main()
{
	vector<vector<int>> board
		= { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
	vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

	std::cout << P13::solution(board, moves);
}
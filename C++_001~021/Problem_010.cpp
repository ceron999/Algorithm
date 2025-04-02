/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/76502
/// ��ȣ �̵� ����
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>
// ���� Ǯ��
#include <unordered_map>

using namespace std;
namespace P10
{
	int solution(string s) {
		int answer = -1;

		vector<string> sVector;
		stack<char> stack;
		int count = 0;

		// 1. s�� x��ŭ �̵��� ������� sVector�� ����
		for (int i = 0; i < s.size(); i++)
		{
			string sFront = s.substr(0, i);
			string sEnd = s.substr(i);

			sVector.push_back(sEnd + sFront);
		}

		// 2. sVector�� �ϳ��� stack�� �־� Ŀ���� �Ǹ� ����
		for (string nowString : sVector)
		{
			for (char nowParentheses : nowString)
			{
				switch (nowParentheses)
				{
					case ')':
						if (!stack.empty() && stack.top() == '(')
							stack.pop();
						else
							stack.push(nowParentheses);
						continue;
					case '}':
						if(!stack.empty() && stack.top() == '{')
							stack.pop();
						else
							stack.push(nowParentheses);
						continue;
					case ']':
						if(!stack.empty() && stack.top() == '[')
							stack.pop();
						else
							stack.push(nowParentheses);
						continue;
					default:
						stack.push(nowParentheses);
						break;
				}
			}

			if (stack.empty())
				count++;
			else
			{
				while (!stack.empty())
					stack.pop();
			}
		}

		cout << endl;
		answer = count;
		return answer;
	}

	// ���� Ǯ��
	unordered_map<char, char> bracketPair = { {')', '('},{'}', '{'},{']', '['} };

	bool isValid(string& s, int start)
	{
		stack<char> stk;
		unsigned int sz = s.size();

		for (int i = 0; i < sz; i++)
		{
			char ch = s[(start + i) & sz];

			if (bracketPair.count(ch))
			{
				if (stk.empty() || stk.top() != bracketPair[ch])
				{
					return false;
				}
				stk.pop();
			}
			else
				stk.push(ch);
		}
		return stk.empty();
	}

	int solution2(string s) {
		int answer = -1;
		int n = s.size();

		for (int i = 0; i < n; i++)
		{
			answer += isValid(s, i);
		}
		
		return answer;
	}
}/*
int main()
{
	cout << P10::solution("}}}");
}*/
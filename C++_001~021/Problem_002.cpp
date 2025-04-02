#include "Problem_002.h"

namespace Problem_002
{
	vector<int> solution(vector<int> lst)
	{
		vector<int> answer;
		sort(lst.begin(), lst.end());
		for (const auto& n : lst) cout << n << ' ';
		cout << endl;

		// unique는 새로운 끝을 반환
		auto newEnd = unique(lst.begin(), lst.end());

		// 새로운 끝에서 마지막까지 지워버린다
		lst.erase(newEnd, lst.end());

		//한번에 끝내는 법
		//lst.erase(unique(lst.begin(), lst.end()), lst.end());
		answer = lst;

		for (const auto& n : lst) cout << n << ' ';
		cout << endl;

		return answer;
	}
}
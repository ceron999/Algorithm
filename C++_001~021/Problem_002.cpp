#include "Problem_002.h"

namespace Problem_002
{
	vector<int> solution(vector<int> lst)
	{
		vector<int> answer;
		sort(lst.begin(), lst.end());
		for (const auto& n : lst) cout << n << ' ';
		cout << endl;

		// unique�� ���ο� ���� ��ȯ
		auto newEnd = unique(lst.begin(), lst.end());

		// ���ο� ������ ���������� ����������
		lst.erase(newEnd, lst.end());

		//�ѹ��� ������ ��
		//lst.erase(unique(lst.begin(), lst.end()), lst.end());
		answer = lst;

		for (const auto& n : lst) cout << n << ' ';
		cout << endl;

		return answer;
	}
}
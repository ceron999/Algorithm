/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12981
/// ���� �����ձ�
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
namespace P21
{
    vector<int> solution(int n, vector<string> words) 
    {
        vector<int> answer{ 0,0 };
        unordered_set<string> hashSet;

        int count = 0;
        int nowTurn = 0;
        for (; count < words.size(); count++)
        {
            // 0. �յ� ���ڰ� �޶� �ٷ� ����
            if (count > 0 && words[count - 1].back() != words[count].front())
            {
                nowTurn = count / n;
                answer = { (count % n) + 1 , nowTurn + 1 };
                return answer;
            }

            auto it = hashSet.find(words[count]);
            // 1. �ؽü¿��� ��Ʈ�� ã�� �� ���� ��
            if (it == hashSet.end())
            {
                // �ؽ� �¿� �߰�
                hashSet.insert(words[count]);
            }
            // 2. �ؽü¿��� ��Ʈ�� ã���� ��(�ߺ�)
            else
            {
                nowTurn = count / n;
                answer = { (count % n) + 1 , nowTurn + 1 };
                return answer;
            }
        }

        return answer;
    }
}

int main()
{
	vector<int> result = P21::solution
                            (3, { "hello", "ostrich", "hat", "tiger", "rose", "elephant", "hat" });
	for (int i : result)
		cout << i << " ";
}
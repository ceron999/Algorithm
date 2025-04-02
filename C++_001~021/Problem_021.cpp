/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12981
/// 영어 끝말잇기
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
            // 0. 앞뒤 글자가 달라도 바로 리턴
            if (count > 0 && words[count - 1].back() != words[count].front())
            {
                nowTurn = count / n;
                answer = { (count % n) + 1 , nowTurn + 1 };
                return answer;
            }

            auto it = hashSet.find(words[count]);
            // 1. 해시셋에서 스트링 찾을 수 없을 때
            if (it == hashSet.end())
            {
                // 해시 셋에 추가
                hashSet.insert(words[count]);
            }
            // 2. 해시셋에서 스트링 찾았을 때(중복)
            else
            {
                nowTurn = count / n;
                answer = { (count % n) + 1 , nowTurn + 1 };
                return answer;
            }
        }

        return answer;
    }

    vector<int> solution2(int n, vector<string> words) {

        vector<int> answer(2, 0);
        unordered_set<string> usedWords;

        usedWords.insert(words[0]);

        // 두 번째 단어부터 끝까지 반복
        for (int i = 1; i < words.size(); ++i) {
            // 단어가 이미 사용되었거나, 끝말잇기 규칙에 맞지 않는 경우
            if (!usedWords.insert(words[i]).second || words[i].front() != words[i - 1].back()) {
                // 플레이어 번호와 턴 번호 저장 후 바로 반환
                answer[0] = i % n + 1;
                answer[1] = i / n + 1;
                return answer;
            }
        }

        // 중간에 탈락하는 플레이어가 없으면 [0, 0] 반환
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
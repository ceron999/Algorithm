/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/132265
/// 롤케이크 자르기
/// 
/// 시간 초과로 실패!!!!!
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
namespace P66
{
    

    int solution(vector<int> topping) {
        int answer = 0;


        for (int i = 0; i<topping.size(); i++)
        {
            unordered_set<int> aPart(topping.begin(), topping.begin() + i);
            unordered_set<int> bPart(topping.begin() + i, topping.end());

            if (aPart.size() == bPart.size())answer++;
        }

        return answer;
    }
}

#include <unordered_map>
namespace P66_Answer
{


    int solution(vector<int> topping) {
        int answer = 0;

        // 남아있는 각 토핑의 개수
        unordered_map<int, int> topping_cnt;
        // 절반에 속한 토핑의 종류
        unordered_set<int> half_topping;

        // 카운터에 각 토핑의 개수를 저장
        for (auto top : topping) {
            if (topping_cnt.find(top) == topping_cnt.end()) {
                topping_cnt[top] = 1;
            }
            else {
                topping_cnt[top]++;
            }
        }

        // 앞에서 부터 토핑을 순서대로 순회
        for (int i = 0; i < topping.size(); i++) {
            // 절반에 속하는 토핑에 추가하고, 남은 토핑개수에서 제외
            half_topping.insert(topping[i]);
            topping_cnt[topping[i]]--;
            // 현재 토핑이 남아있지 않은 경우 남은 토핑 목록에서 삭제
            if (topping_cnt[topping[i]] == 0) {
                topping_cnt.erase(topping[i]);
            }
            // 공평한 경우 카운팅
            if (topping_cnt.size() == half_topping.size()) {
                answer++;
            }
        }

        return answer;
    }
}

//int main()
//{
//    int result = P66::solution({ 1, 2, 1, 3, 1, 4, 1, 2 });
//
//        cout << result << " ";
//}
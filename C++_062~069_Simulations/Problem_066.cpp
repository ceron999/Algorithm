/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/132265
/// ������ũ �ڸ���
/// 
/// �ð� �ʰ��� ����!!!!!
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

        // �����ִ� �� ������ ����
        unordered_map<int, int> topping_cnt;
        // ���ݿ� ���� ������ ����
        unordered_set<int> half_topping;

        // ī���Ϳ� �� ������ ������ ����
        for (auto top : topping) {
            if (topping_cnt.find(top) == topping_cnt.end()) {
                topping_cnt[top] = 1;
            }
            else {
                topping_cnt[top]++;
            }
        }

        // �տ��� ���� ������ ������� ��ȸ
        for (int i = 0; i < topping.size(); i++) {
            // ���ݿ� ���ϴ� ���ο� �߰��ϰ�, ���� ���ΰ������� ����
            half_topping.insert(topping[i]);
            topping_cnt[topping[i]]--;
            // ���� ������ �������� ���� ��� ���� ���� ��Ͽ��� ����
            if (topping_cnt[topping[i]] == 0) {
                topping_cnt.erase(topping[i]);
            }
            // ������ ��� ī����
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
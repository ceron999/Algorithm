/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/92334
/// �Ű� ��� �ޱ�
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
namespace P26
{
    vector<int> solution(vector<string> id_list, vector<string> report, int k) {
        vector<int> answer;
        return answer;
    }
}

int main()
{
    vector<int> result = P26::solution({ "muzi", "frodo", "apeach", "neo" },
        { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" });
    for (int i : result)
        cout << i << " ";
}
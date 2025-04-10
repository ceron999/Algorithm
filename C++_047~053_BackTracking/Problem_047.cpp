/// <summary>
/// 
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
namespace P47
{
    set<set<int>> result;
    int sum(set<int> sets)
    {
        int sum = 0;
        for (int i : sets)
            sum += i;
        return sum;
    }

    void backTracking(int N, set<int> curr)
    {
        int sumCurr = sum(curr);
        if (sumCurr == 10)
        {
            result.insert(curr);
            return;
        }
        if (sumCurr > 10) return;

        vector<int> remain;
        for (int i = 1; i <= N; i++)
        {
            if (curr.find(i) == curr.end())
                remain.push_back(i);
        }

        for (int i : remain)
        {
            auto newCurr = curr;
            newCurr.insert(i);
            backTracking(N, newCurr);
        }
    }

    vector<vector<int>> solution(int N)
    {
        vector<vector<int>> answer;
        backTracking(N, {});
        for (const auto& answerPart : result)
        {
            vector<int> answerVector;
            for (int i : answerPart)
                answerVector.push_back(i);

            answer.push_back(answerVector);
        }

        return answer;
    }
}

namespace P47_Answer
{
    vector<vector<int>> results;
    vector<int> selected_nums;

    void backtrack(int N, int sum, int start) {
        // 합이 10인경우, 조합을 결과에 추가하고 종료
        if (sum == 10) {
            results.push_back(selected_nums);
            return;
        }
        for (int i = start; i <= N; ++i) {
            // 합이 10보다 적은 경우, 가능한 조합을 계속 확인
            if (sum + i <= 10) {
                selected_nums.push_back(i);
                backtrack(N, sum + i, i + 1);
                selected_nums.pop_back();
            }
        }
    }

    vector<vector<int>> solution(int N) {
        // 숫자 1부터 백트래킹 시작
        backtrack(N, 0, 1);
        return results;
    }
}
//int main()
//{
//    vector<vector<int>> result = P47::solution(7);
//
//    for (int i = 0; i < result.size(); i++)
//    {
//        for (int j = 0; j < result[i].size(); j++)
//            cout << result[i][j] << " ";
//
//        cout << endl;
//    }
//}
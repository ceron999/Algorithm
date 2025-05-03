/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/92344
/// 파괴되지 않은 건물
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P99
{
    vector<vector<int>> prefixSum;

    void UseSkill(vector<vector<int>>& board, vector<int> skill)
    {
        // 적의 스킬이라면 데미지를 감소로 변환
        if (skill[0] == 1)
            skill[5] *= -1;
        
        int startRow = skill[1];
        int startCol = skill[2];
        int endRow = skill[3] + 1;
        int endCol = skill[4] + 1;
        int damage = skill[5];


        prefixSum[startRow][startCol] += damage;
        prefixSum[endRow][startCol] -= damage;
        prefixSum[startRow][endCol] -= damage;
        prefixSum[endRow][endCol] += damage;

    }

    int solution(vector<vector<int>> board, vector<vector<int>> skill) {
        int answer = 0;

        int n = board.size();
        int m = board[0].size();
        prefixSum.resize(n + 1, vector<int>(m + 1, 0));

        for (vector<int>& nowSkill : skill)
        {
            UseSkill(board, nowSkill);
        }

        // 세로 누적
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= m; j++)
                prefixSum[i][j] += prefixSum[i - 1][j];
        // 가로 누적
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++)
                prefixSum[i][j] += prefixSum[i][j - 1];
        // 업데이트
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                board[i][j] += prefixSum[i][j];

                if (board[i][j] > 0)
                    answer++;
            }
        return answer;
    }
}

//int main()
//{
//    vector<vector<int>> board =
//    {
//        {5, 5, 5, 5, 5},
//        {5, 5, 5, 5, 5},
//        {5, 5, 5, 5, 5},
//        {5, 5, 5, 5, 5}
//    };
//    vector<vector<int>> skill = 
//    {
//        {1, 0, 0, 3, 4, 4},
//        {1, 2, 0, 2, 3, 2},
//        {2, 1, 0, 3, 1, 2},
//        {1, 0, 1, 3, 3, 1}
//    };
//	int result = P99::solution(board, skill);
//
//		cout << result << " ";
//}
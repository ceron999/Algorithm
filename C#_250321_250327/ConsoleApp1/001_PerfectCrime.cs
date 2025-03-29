namespace Num1_Problem
{
    using System;
    using System.Collections.Generic;
    public class Solution
    {
        int answer = int.MaxValue; // A의 최소 흔적을 저장할 변수
        HashSet<(int, int, int)> visit;
        public int solution(int[,] info, int n, int m)
        {
            answer = int.MaxValue;
            visit = new HashSet<(int, int, int)>();
            Dfs(info, 0, 0, 0, n, m);
            return answer != int.MaxValue ? answer : -1;
        }

        private void Dfs(int[,] info, int idx, int sumA, int sumB, int n, int m)
        {
            if (sumA >= n || sumB >= m || sumA >= answer)
            {
                return;
            }

            if (visit.Contains((idx, sumA, sumB))) return;
            visit.Add((idx, sumA, sumB));

            if (idx == info.GetLength(0))
            {
                answer = Math.Min(answer, sumA);
                return;
            }


            Dfs(info, idx + 1, sumA + info[idx, 0], sumB, n, m);
            Dfs(info, idx + 1, sumA, sumB + info[idx, 1], n, m);
        }
    }
}

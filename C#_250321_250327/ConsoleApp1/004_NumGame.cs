
namespace Num4_Problem
{
    using System;
    using System.Collections.Generic;

    /// <summary>
    /// A ,B 숫자놀이
    /// A보다 B가 더 많이 이겨야 하며 최대 승점을 구하여라
    /// 
    /// sol
    /// 1. A, B를 Sort한 후 Battle에서 서로 대결을 시킴
    /// 2. 여기서 가장 높은 승률을 가질 수 있는 방법을 찾기 위해 B를 1칸 아래씩 내려가며 대결
    /// 3. 최고 승점을 찾아냄
    /// </summary>

    public class Solution
    {
        // 극한의 효율
        public int solution(int[] A, int[] B)
        {
            Array.Sort(A);
            Array.Sort(B);

            int answer = 0;
            int aIndex = 0;
            int bIndex = 0;

            while (aIndex < A.Length && bIndex < B.Length)
            {
                if (B[bIndex] > A[aIndex])
                {
                    answer++;
                    aIndex++;
                    bIndex++;
                }
                else
                {
                    bIndex++;
                }
            }
            Console.WriteLine(answer);
            return answer;
        }

        public int solution2(int[] A, int[] B)
        {
            int answer = -1;

            Array.Sort(A);
            Array.Sort(B);

            Battle battle = new Battle(A, B);

            battle.StartBattle();
            answer = battle.winScore;
            Console.WriteLine(answer);

            return answer;
        }
    }

    public class Battle
    {
        public int winScore;
        public int[] aTeam;
        public int[] bTeam;

        public Battle(int[] A, int[] B)
        {
            winScore = -1;

            aTeam = A;
            bTeam = B;
        }

        // Sort된 A, B와 비교하며 B가 높다면 result++을 진행한다
        // 그리고 result의 추가적 비교를 위해 B의 순서를 1칸 미뤄 작업해본다
        // 끝까지 진행한 뒤 result 중 최댓값을 winScore로 저장한다.
        public void StartBattle()
        {
            int result = 0;
            int battleCount = aTeam.Length;

            for (int bSwitchIndex = 0; bSwitchIndex < battleCount; bSwitchIndex++)
            {
                for (int aIndex = 0; aIndex < battleCount; aIndex++)
                {
                    int bIndex = aIndex + bSwitchIndex;

                    if (bIndex >= battleCount)
                        continue;

                    if (aTeam[aIndex] < bTeam[bIndex])
                    {
                        result++;
                    }
                }
                if (result > winScore) winScore = result;
                result = 0;
            }
            
        }
    }
}

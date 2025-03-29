// source
// https://school.programmers.co.kr/learn/courses/30/lessons/42578

/// <summary>
/// 
/// </summary>

namespace Num10_Problem
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    public class Solution
    {
        public int solution(string[,] clothes)
        {
            int answer = 0;

            Coodinator coodinator = new Coodinator(clothes);
            answer = coodinator.Coodinate();

            //Console.WriteLine(answer);

            return answer;
        }
    }

    public class Coodinator
    {
        // 동일한 옷은 없다.
        public string[,] cloths_Types;
        public Dictionary<string, int> clothesCount;

        public Coodinator(string[,] clothes)
        {
            cloths_Types = clothes;
            clothesCount = new Dictionary<string, int>();

            // 받은 (옷, 타입)string 을 (타입, 갯수) Dictionary로 저장
            for (int i = 0; i < cloths_Types.GetLength(0); i++)
            {
                string nowClothes = cloths_Types[i, 1];

                if (clothesCount.ContainsKey(nowClothes))
                {
                    clothesCount[nowClothes]++;
                }
                else
                {
                    clothesCount.Add(nowClothes, 1);
                }
            }
        }

        public int Coodinate()
        {
            int answer = 1;
            foreach (var count in clothesCount.Values)
            {
                answer *= (count + 1);  // 안 입는 경우까지 포함
            }

            answer -= 1; // 전부 안 입는 경우 제거
            return answer;
        }
    }
}

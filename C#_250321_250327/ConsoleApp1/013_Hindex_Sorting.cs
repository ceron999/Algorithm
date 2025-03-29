// source
// https://school.programmers.co.kr/learn/courses/30/lessons/42747

/// <summary>
/// H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 
/// 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 
/// 위키백과1에 따르면, H-Index는 다음과 같이 구합니다.
/// 어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 
/// 나머지 논문이 h번 이하 인용되었다면 
/// h의 최댓값이 이 과학자의 H-Index입니다.
/// 
/// citations : 논문의 인용횟수 배열
/// 
/// sol
/// 1. citation.sum / citation.count 근처의 숫자가 있는지 확인
/// 2. 
/// </summary>

namespace Num13_Problem
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    public class Solution
    {
        public int solution(int[] citations)
        {
            int answer = 0;

            HIndex hIndex = new HIndex(citations);
            hIndex.UpdateHIndex();
            answer = hIndex.nowIndex;

            Console.WriteLine(answer);

            return answer;
        }

        public int solution2(int[] citations)
        {
            Array.Sort(citations);
            Array.Reverse(citations); // 내림차순 정렬

            int h = 0;
            for (int i = 0; i < citations.Length; i++)
            {
                if (citations[i] >= i + 1)
                {
                    h = i + 1;
                }
                else
                {
                    break;
                }
            }

            return h;
        }
    }

    public class HIndex
    {
        public int[] citations;
        public int nowIndex;
        public HashSet<int> citationNums;

        public HIndex(int[] inputCitations)
        {
            citations = inputCitations;
            Array.Sort(citations);

            citationNums = new HashSet<int>(); ;

            for (int i = 0; i < citations.Max(); i++)
            {
                citationNums.Add(i);
            }

            Console.WriteLine(string.Join(", ", citationNums));
        }

        public void UpdateHIndex()
        {
            while (citationNums.Count > 0)
            {
                int testIndex = citationNums.Min();
                // 인덱스보다 작은 수와 큰 수 카운트용 
                int smallCitation = 0;
                int largeCitation = citations.Length;

                foreach (int currCitation in citations)
                {
                    //현재 인용수가 index 이상이면 저장
                    if (testIndex > currCitation)
                    {
                        smallCitation++;
                        largeCitation--;
                    }
                    else
                    {
                        // 조건(largeCitation이 index보다 큼 && smallCitation이 index보다 작음
                        if (smallCitation <= testIndex && largeCitation >= testIndex)
                        {
                            nowIndex = testIndex;
                            citationNums.Remove(testIndex);
                            break;
                        }
                        else
                        {
                            return;
                        }
                    }
                }
            }
        }
    }
}

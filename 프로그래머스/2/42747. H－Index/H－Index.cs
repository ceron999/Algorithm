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
        
        citationNums = new HashSet<int>();

        for(int i = 0; i < citations.Max() ; i++)
        {
            citationNums.Add(i);
        }

        Console.WriteLine(string.Join(", ", citationNums));
    }

    public void UpdateHIndex()
    {
        while(citationNums.Count > 0)
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
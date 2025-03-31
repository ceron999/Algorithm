 using System;
 using System.Linq;
 using System.Collections;
 using System.Collections.Generic;
 using System.Text;

/// <summary>
/// numbers. Length : 1~7
/// numbers -> 0~9로 이루어짐
/// 
/// sol
/// 1. str로 들어온 numbers를 int[]로 변환
/// 2. 해당 배열로 만들 수 있는 숫자들을 int[]에 저장
/// 3. 하나하나 소수 확인
/// 4. 총 개수 리턴
/// </summary>

public class Solution
{
    public int solution(string numbers)
    {
        int answer = 0;

        PrimeConverter pc = new PrimeConverter(numbers);

        answer = pc.CountPrime();

        //temp
        Console.Write("\n[");
        foreach (int number in pc.combinedPrime)
        {
            Console.Write($"{number}, ");
        }
        Console.Write("]");
        Console.WriteLine(answer);
        return answer;
    }
}

public class PrimeConverter
{
    public string numString;
    public List<int> combinedPrime;
    public int primeCount;

    public PrimeConverter(string inputString)
    {
        numString = inputString;

        combinedPrime = new List<int>();
        CombineNumsDFS(inputString);

        combinedPrime = combinedPrime.Distinct().ToList();
        combinedPrime.Sort();


        primeCount = 0;
    }

    // 숫자 조합을 생성한다
    private void CombineNumsDFS(string current)
    {
        if (current.Length == 1)
        {
            for(int i =0; i< current.Length; i++)
            {
                combinedPrime.Add(int.Parse(current.Substring(i,1)));
            }
            return;
        }
        Permute(string.Empty, current);

        for (int i = 0; i < current.Length; i++)
        {
            StringBuilder sb = new StringBuilder(current);
            sb.Remove(i, 1);
            CombineNumsDFS(sb.ToString());
        }
    }

    private void Permute(string prefix, string remainder)
    {
        // 1개면 그냥 하나 넣고 종료
        if (remainder.Length == 0)
        {
            combinedPrime.Add(int.Parse(prefix));
            return;
        }

        for (int i = 0; i < remainder.Length; i++)
        {
            string newPrefix = prefix + remainder[i];
            string newRemainder = remainder.Remove(i, 1);
            Permute(newPrefix, newRemainder);
        }
    }

    // 소수의 개수를 센다
    public int CountPrime()
    {
        int result = 0;

        //소수 확인
        for (int numsIndex = 0; numsIndex < combinedPrime.Count; numsIndex++)
        {
            if(combinedPrime[numsIndex] == 0 || combinedPrime[numsIndex] == 1)
                continue;
            else if (combinedPrime[numsIndex] == 2 || combinedPrime[numsIndex] == 3)
            {
                result++;
                continue;
            }

            for(int testNum = 2; testNum * testNum < combinedPrime[numsIndex]; testNum++)
            {
                //약수를 찾으면 중단
                if (combinedPrime[numsIndex] % testNum == 0)
                {
                    break;
                }

                // 마지막까지 약수를 못찾으면 ++
                if ((testNum + 1) * (testNum + 1) > combinedPrime[numsIndex])
                    result++;
            }
        }

        return result;
    }
}
using System;
using System.Collections;
using System.Collections.Generic;

/// <summary>
/// sol
/// case 1 : 짝수 -> 그냥 + 1
/// case 2-1 : 홀수(단 모두 1이 아닌 1101같은거) 
///         -> 최초로 0이 나오는 위치를 1로 그 전 위치를 0으로 수정(1101 -> 1110)
/// case 2-2 : 홀수(1111) 
///         -> 그냥 제일 앞에 1을 추가하고 두번째로 큰 값을 가지는 1을 0으로 변환(1111 -> 10111)
/// </summary>

public class Solution
{
    public long[] solution(long[] numbers)
    {
        long[] answer = new long[numbers.Length];
        
        for(int i =0; i< numbers.Length; i++)
        {
            BitCalculator bitCalculator = new BitCalculator(numbers[i]);

            answer[i] = bitCalculator.Func();
        }

        return answer;
    }
}

public class BitCalculator
{
    public long beforeNum;
    public BitArray beforeBit;
    // private HashSet<(int, int, int)> visits;

    // 초기화 : numbers를 BitArray로 변환하여 before에 각각 저장
    public BitCalculator(long numbers)
    {
        beforeNum = numbers;
        beforeBit = new BitArray(0);
        ConvertNumToBit(beforeNum, ref beforeBit);
    }

    // input값인 long[]을 bit로 변환하여 outputBit으로 반환
    public void ConvertNumToBit(long inputNum, ref BitArray outputBit)
    {
        byte[] bytes = BitConverter.GetBytes(inputNum);
        outputBit = new BitArray(bytes);
    }

    // 결과값을 변환하여 숫자로 변환 후 answer에 반환
    public void ConvertBitToNum(BitArray inputBit, ref long outputNum)
    {
        long temp = 0;
        for (int bitIndex = 0; bitIndex < inputBit.Count; bitIndex++)
        {
            if (inputBit[bitIndex])
                // bit 위치 조정
                temp |= (1L << bitIndex);
        }
        outputNum = temp;
    }

    public long Func()
    {
        long result = 0L;

        // case 1: 짝수 -> +1
        if (beforeNum % 2 == 0) result = ++beforeNum;


        // case 2: 홀수
        else
        {
            int maxIndex = 0;       // bit 중 가장 높은 value를 가지는 1의 위치
            for (int i = beforeBit.Count - 1; i >= 0; i--)
            {
                if (beforeBit[i])
                {
                    maxIndex = i;
                    break;
                }
            }

            // 모두 1이 아닌 경우(1101) -> 01을 찾아 10으로 수정
            if (!IsMaxValue(maxIndex))
            {
                int index = 0;
                foreach(bool bit in beforeBit)
                {
                    if (!bit) break;
                    index++;
                }

                beforeBit[index - 1] = false;
                beforeBit[index] = true;
                ConvertBitToNum(beforeBit, ref result);
            }

            // 모두 1 -> 제일 뒤에 1 추가하고 두번째로 큰 1을 뺀다
            else
            {
                beforeBit[maxIndex] = false;
                beforeBit[maxIndex + 1] = true;
                ConvertBitToNum(beforeBit, ref result);
            }

        }
        return result;
    }

    private bool IsMaxValue(int maxIndex)
    {
        for(int i = 0; i <= maxIndex; i++)
        {
            if(!beforeBit[i])
                return false;
        }
        return true;
    }

    #region Debug Func
    public void DebugBeforeBit()
    {
        for (int bitIndex = 0; bitIndex < beforeBit.Count; bitIndex++)
        {
            Console.Write(beforeBit[bitIndex] ? "1" : "0");
        }
        Console.Write(" ");
    }
    #endregion
}
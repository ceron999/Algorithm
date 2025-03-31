using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int[] solution(int[,] arr)
    {
        int[] answer = new int[] { };

        QuadCompression qc = new QuadCompression(arr);
        qc.Compress(arr);
        answer = qc.Result;

        Console.WriteLine(string.Join(",", answer));
        return answer;
    }
}

public class QuadCompression
{
    int[,] binaryArr;
    public int[] Result 
    { 
        get { return result; }
        private set { result = value; }
    }
    int[] result;           // int[0] = 0 개수, int[1] = 1 개수


    public QuadCompression(int[,] inputArr)
    {
        binaryArr = inputArr;
        result = new int[]{0, 0};
    }

    public void Compress(int[,] curr)
    {
        // 0. atomic하면 쪼갤 수 없으므로 그냥 계산
        if(curr.Length == 1)
        {
            UpdateResult(curr[0, 0]);
            return;
        }

        // 1. curr의 숫자가 모두 동일한지 확인
        bool isAllSame = true;          // 모두 같은 숫자이면 true를 반환
        int firstNum = curr[0, 0];      // 현재 배열의 첫 숫자
        foreach (int num in curr)
        {
            // 하나라도 다르면 isAllSame = false
            if (num != firstNum)
            {
                isAllSame = false;
                break;
            }
        }

        // 2. 모두 동일하다면 result에 기록하고 return;
        if(isAllSame)
        {
            UpdateResult(firstNum);
            return;
        }

        // 1. 현재 배열의 행과 열을 2로 분할한다. 
        int searchRow = curr.GetLength(0) / 2;
        int searchCol = curr.GetLength(1) / 2;
        int[,] newArr = new int[searchRow, searchCol];

        // 2. 분할한 구역에서 압축이 가능한지 확인한다. 
        for (int startRow = 0; startRow < curr.GetLength(0); startRow += searchRow)
        {
            for (int startCol = 0; startCol < curr.GetLength(1); startCol+= searchCol)
            {
                newArr = SaperateArr(curr, startRow, startCol);

                // 3. 더 작은 조각으로 나누어 압축을 진행한다.
                Compress(newArr);
            }
        }

    }

    // num이 0이면 result[0]++
    // num이 1이면 result[1]++하는 함수
    private void UpdateResult(int num)
    {
        if (num == 0) result[0]++;
        else result[1]++;
    }

    private int[,] SaperateArr(int[,] inputArr, int startRow, int startCol)
    {
        int size = inputArr.GetLength(0) / 2;
        int[,] result = new int[size, size];

        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                result[row,col] = inputArr[startRow + row, startCol + col];
            }
        }

        return result;
    }

}
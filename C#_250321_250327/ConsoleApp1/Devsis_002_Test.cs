namespace Dev_Problem_002

{
    /// <summary>
    /// 농사지을 땅 찾기
    /// field : 전체 영역
    /// farmSize : 한 변의 길이
    /// answer : 최소 돌 캐기 횟수
    /// 
    /// 0 빔, 1 돌, 2 독
    /// sol
    /// 1. farmSize가 가능한지 확인한다
    /// </summary>

    using System;
    using System.Collections.Generic;
    using System.Linq;

    public class Solution
    {
        public int solution(int[,] field, int farmSize)
        {
            int answer = 0;

            // 0. farmSize보다 작은 경우 무조건 불가능 -> -1 반환
            if (field.GetLength(0) < farmSize || field.GetLength(1) < farmSize) 
                return -1;

            FarmFinder farmFinder = new FarmFinder(field, farmSize);

            // 1. 활용 가능한 농장 찾아 최솟값 설정
            farmFinder.Find(0, 0);

            answer = (farmFinder.MinStone != int.MaxValue) ? farmFinder.MinStone : -1;
            Console.WriteLine(answer);
            return answer;
        }
    }

    public class FarmFinder
    {
        int[,] field;
        int farmSize;

        public int MinStone
        {
            get
            {
                return minStone;
            }
            private set
            {
                minStone = value;
            }
        }
        int minStone;

        public FarmFinder(int[,] inputField, int inputFarmSize)
        {
            field = inputField;
            farmSize = inputFarmSize;
            minStone = int.MaxValue;
        }

        public void Find(int startRow, int startCol)
        {
            // 확인 범위를 초과하는 경우 제외한다.
            if (startRow + farmSize > field.GetLength(0) || startCol + farmSize > field.GetLength(1))
                return;

            int nowStone = 0;

            // 현재 구역을 확인한다
            for (int row = startRow; row < startRow + farmSize; row++)
            {
                for (int col = startCol; col < startCol + farmSize; col++)
                {
                    if (field[row, col] == 2)
                        return;
                    else if (field[row, col] == 1)
                        nowStone++;
                }
            }

            // 최솟값을 저장한다
            minStone = (nowStone < minStone) ? nowStone : minStone;

            Find(startRow + 1, startCol);
            Find(startRow, startCol + 1);
        }
    }
}


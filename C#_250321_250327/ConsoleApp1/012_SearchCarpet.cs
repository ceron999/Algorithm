// source
// https://school.programmers.co.kr/learn/courses/30/lessons/42842

/// <summary>
/// brown, yellow의 색의 개수를 통해 yellow가 brown이 만든 직사각형 안에 모두 들어가는 직사각형을 구하쇼
/// brown : 외곽 테두리
/// yellow : 내부
/// 
/// [가로, 세로] && 가로 >= 세로
/// </summary>

namespace Num12_Problem
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    public class Solution
    {
        public int[] solution(int brown, int yellow)
        {
            int[] answer = new int[] { };

            SquareMaker boxMaker= new SquareMaker(brown, yellow);

            answer = boxMaker.Square;
            Console.WriteLine(string.Join(",", answer));

            return answer;
        }
    }

    public class SquareMaker
    {
        public int brownCount;
        public int yellowCount;
        public int sum;

        public int[] Square
        {
            get
            {
                return square;
            }
            private set
            {
                square = value;
            }
        }

        int[] square;
        List<(int width, int height)> squareList;

        public SquareMaker(int inputBrownCount, int inputYellowCount)
        {
            brownCount = inputBrownCount;
            yellowCount = inputYellowCount;
            sum = brownCount + yellowCount;

            square = new int[2] { 0, 0 };
            squareList = new List<(int width, int height)>();
            MakeSquareList();
    }

        private void MakeSquareList()
        {
            for(int i =3; i * i <= sum; i++)
            {
                if(sum % i == 0)
                {
                    if(IsAvailableSquare(sum / i, i))
                    {
                        square[0] = sum / i;
                        square[1] = i;
                    }
                }
            }
        }

        // 적절한 사각형인지 확인
        private bool IsAvailableSquare(int width, int height)
        {
            int currBrownCount = width * 2 + height * 2 - 4;
            int currYellowCount = (width - 2) * (height - 2);

            if (currBrownCount == brownCount && currYellowCount == yellowCount)
                return true;
            else
                return false;
        }
    }

}

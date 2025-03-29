namespace Dev_Problem_003

{
    /// <summary>
    /// objectBallPosList : 현재 objball의 중심 위치 배열
    /// hitVector : cueBall이 나아가는 방향
    /// answer : cueBall이 처음으로 마주치는 obj ball의 인덱스
    /// sol
    /// 원과의 최단거리 계산 후 가장 처음으로 3 이하가 나타나는 케이스 분류
    /// 해당 케이스에서 가장 원점과 가까운 오브젝트 선택 후 인덱스 반환
    /// 
    /// 점과 직선 사이의 거리 공식
    /// 원의 중심(x1,y1) , 직선의 방정식 ax + by + c =0일 때
    /// d = | ax1 + by1 + c | / root(a^2 + b^2)
    /// 
    /// 직선의 방정식 : hitVector[0] * x - hitVector[1] * y
    /// </summary>

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Numerics;

    public class Solution
    {
        public const double BallDiameter = 2;
        public int solution(double[,] objectBallPosList, double[] hitVector)
        {
            int answer = -2;

            MinDistCalculator minDistCalculator = new MinDistCalculator(objectBallPosList, hitVector);

            answer = minDistCalculator.minIndex;
            return answer;
        }

        public class MinDistCalculator
        {
            public double[,] objectBallPosList;
            double[] hitVector;

            public List<double> minDistList;
            public double minDist;
            public int minIndex;

            public MinDistCalculator(double[,] inputObjectBallPosList, double[] inputHitVector)
            {
                objectBallPosList = inputObjectBallPosList;
                hitVector = inputHitVector;
                minDist = int.MaxValue;
                minIndex = -1;

                minDistList = new List<double>();
                SetMinDistList();
            }

            

            private void SetMinDistList()
            {
                double nowDist = 0;
                for(int i = 0; i < objectBallPosList.GetLength(0); i++)
                {
                    nowDist = CalculateMinDist(objectBallPosList[i,0],objectBallPosList[i, 1]);
                    minDistList.Add(nowDist);

                    // 원점과 최소 거리를 확인한다
                    double originDist = CalculateOriginDist(objectBallPosList[i, 0], objectBallPosList[i, 1]);
                   
                    
                    if (minDist > originDist && nowDist <= 3)
                    {
                        minDist = originDist;
                        minIndex = i;
                    }

                }
                Console.WriteLine(minIndex);
                //Console.WriteLine(string.Join(", ", minDistList));
            }

            // 식 계산
            private double CalculateMinDist(double xPos, double yPos)
            {
                double result = 0;

                double numerator = hitVector[0] * xPos - hitVector[1] * yPos;
                
                double denominator = hitVector[0] * hitVector[0] + hitVector[1] * hitVector[1];

                result = Math.Abs(numerator) / Math.Sqrt(denominator);

                return result;
            }

            // 원점과의 거리 계산
            private double CalculateOriginDist(double xPos, double yPos)
            {
                double result = Math.Sqrt(xPos * xPos + yPos * yPos);

                return result;
            }
        }
    }
}

// source
// https://school.programmers.co.kr/learn/courses/30/lessons/42583

/// <summary>
/// 다리를 지나는 트럭
/// bridge_length : 다리에 오를 최대 트럭 수, 거리
/// weight : 최대 무게
/// truck_weights : 트럭 리스트
/// </summary>

namespace Num7_Problem
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    public class Solution
    {
        public int solution(int bridge_length, int weight, int[] truck_weights)
        {
            int answer = 0;

            // 교통 정리 인스턴스 생성
            TraficController tc = new TraficController(bridge_length, weight, truck_weights);
            answer = tc.ControlTrafic();
            Console.WriteLine(answer);
            return answer;
        }
    }

    public class TraficController
    {
        int spendTime;
        int bridge_length;
        int weight;
        public Queue<int> truckQueue = new Queue<int>();           // 총 트럭
        public Queue<(int weight, int enterTime)> bridgeTrucks = new Queue<(int, int)>();        // 진행중 트럭
        public Queue<int> arrivedTruckQueue = new Queue<int>();         // 도착 트럭

        public TraficController(int inputLength, int inputWeight, int[] inputTrucks)
        {
            spendTime = 0;
            bridge_length = inputLength;
            weight = inputWeight;

            foreach (int truck in inputTrucks)
            {
                truckQueue.Enqueue(truck);
            }
        }

        public int ControlTrafic()
        {
            int nowweight = 0;

            while (truckQueue.Count > 0 || bridgeTrucks.Count > 0)
            {
                spendTime++;

                // 1. 가장 오래 운전 중인 트럭이 도착했는지 확인
                if(bridgeTrucks.Count > 0
                    && spendTime - bridgeTrucks.Peek().enterTime >= bridge_length)
                {
                    nowweight -= bridgeTrucks.Dequeue().weight;
                }

                // 2. 트럭 남아있음 + 무게 초과 x + 트럭 개수 추가 가능 이면 트럭 추가
                if (truckQueue.Count > 0 
                    && nowweight + truckQueue.Peek() <= weight 
                    && bridgeTrucks.Count < bridge_length)
                {
                    int truck = truckQueue.Dequeue();
                    nowweight += truck;
                    bridgeTrucks.Enqueue((truck, spendTime));
                }
            }

            return spendTime;
        }

        #region Old
        //public int OldControlTrafic()
        //{
        //    int result = 0;
        //    int maxTruckCount = totalTruckQueue.Count;

        //    // 전부 도착할 때까지 루프
        //    while(arrivedTruckQueue.Count < maxTruckCount)
        //    {
        //        // 1. 최대한 많은 트럭을 차도로 보냄
        //        result = GoOverTruck();
        //    }

        //    return result;
        //}
        //public int GoOverTruck()
        //{
        //    int spendTime = 0;
        //    int nowTruckCount = 0;

        //    foreach(int truck in totalTruckQueue)
        //    {
        //        // 1. (최대 무게 && 최대 트럭 수)를 만족하는 차량을 도착시킴
        //        // 2. 도착하는데 소요된 시간을 spendTime에 추가
        //        if (goneOverTruckQueue.Sum() + truck > weight || nowTruckCount >= bridge_length)
        //        {
        //            spendTime += ArriveTruck();
        //            nowTruckCount = 0;
        //        }

        //        spendTime++;
        //        nowTruckCount++;
        //        goneOverTruckQueue.Enqueue(truck);
        //    }

        //    spendTime += ArriveTruck();

        //    return spendTime;
        //}

        //// 도착에 소요되는 시간 계산 함수
        //public int ArriveTruck()
        //{
        //    int arriveTime = 0;
            
        //    foreach(int truck in goneOverTruckQueue)
        //    {
        //        arriveTime++;
        //        arrivedTruckQueue.Enqueue(truck);
        //    }

        //    goneOverTruckQueue.Clear();

        //    return arriveTime;
        //}
        #endregion
    }
}

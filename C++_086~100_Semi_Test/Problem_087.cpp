/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/150369
/// 택배 배달과 수거하기
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
namespace P87
{
    long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
        long long answer = 0;

        // 배달할 개수, 수거할 개수 스택
        vector<vector<int>> houseVector;
        for (int i = 0; i < n; i++)
        {
            vector<int> curr = { deliveries[i], pickups[i] };
            houseVector.push_back(curr);
        }

        int currIdx = 0;
        int currDeliverSize = 0;
        int currPickSize = 0;

        while (currIdx != n)
        {
            // 배달할 크기 지정
            if (currDeliverSize + houseVector[currIdx][0] <= cap)
            {
                currDeliverSize += houseVector[currIdx][0];
                houseVector[currIdx][0] = 0;
            }
            else
            {
                houseVector[currIdx][0] -= (cap - currDeliverSize);
                currDeliverSize = cap;
            }

            // 수거할 크기 지정
            if (currPickSize + houseVector[currIdx][1] <= cap)
            {
                currPickSize += houseVector[currIdx][1];
                houseVector[currIdx][1] = 0;
            }
            else
            {
                houseVector[currIdx][1] -= (cap - currPickSize);
                currPickSize = cap;
            }

            if (currIdx + 1 < n)
            {
                if (currDeliverSize + houseVector[currIdx + 1][0] > cap
                    || currPickSize + houseVector[currIdx][1] > cap)
                {
                    answer += (currIdx + 1) * 2;
                    currDeliverSize = 0;
                    currPickSize = 0;
                    continue;
                }

            }
            else
            {
                if (houseVector[n - 1][0] == 0
                    || houseVector[n - 1][1] == 0)
                {
                    answer += (currIdx + 1) * 2;
                    currDeliverSize = 0;
                    currPickSize = 0;
                    break;
                }
            }


            if (houseVector[currIdx][0] == 0 && houseVector[currIdx][1] == 0)
                currIdx++;
            

        }

        return answer;
    }
}

namespace P87_Answer
{
    // v 벡터에서 dx 용량만큼 제거하는 함수
    void RemoveCargo(vector<int>& cargo, int capacity) {
        while (!cargo.empty() && capacity) {
            // 현재 용량이 마지막 화물의 무게보다 크거나 같으면 화물을 제거
            if (cargo.back() <= capacity) {
                capacity -= cargo.back();
                cargo.pop_back();
            }
            else {
                // 현재 용량으로 화물의 무게를 감소시키고, 용량을 0으로 설정
                cargo.back() -= capacity;
                capacity = 0;
            }
        }
    }

    // 항구에서 화물을 옮기는 데 필요한 최소 시간을 계산하는 함수
    long long solution(int cap, int n, vector<int> A, vector<int> B) {
        long long int answer = 0;
        while (!A.empty() || !B.empty()) {
            // A, B에서 무게가 0인 화물 제거
            while (!A.empty() && A.back() == 0) A.pop_back();
            while (!B.empty() && B.back() == 0) B.pop_back();

            // A와 B 중 더 긴 벡터의 길이를 dx로 설정
            int trips = max(A.size(), B.size());
            // 왕복 횟수를 계산하여 정답에 추가
            answer += trips * 2;

            // A, B에서 cap 용량만큼 화물 제거
            RemoveCargo(A, cap);
            RemoveCargo(B, cap);
        }

        return answer;
    }
}

//int main()
//{
//    //long long result = P87::solution(4, 5, { 1, 0, 3, 1, 2 }, { 0, 3, 0, 4, 0 });
//    long long result = P87::solution(2, 7, { 1, 0, 2, 0, 1, 0, 2 }, { 0, 2, 0, 1, 0, 2, 0 });
//
//		cout << result << " ";
//}
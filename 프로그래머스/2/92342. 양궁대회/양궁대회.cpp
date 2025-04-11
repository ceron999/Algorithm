#include <string>
#include <vector>

using namespace std;

vector<int> result;
int N;
int maxDiff;

 void SaveSmallValueVec(const vector<int>& ryanNewVec)
 {
     if (result.empty()) {
         result = ryanNewVec;
         return;
     }

     for (int i = 10; i >= 0; --i)  // 0점부터
     {
         if (ryanNewVec[i] > result[i]) {
             result = ryanNewVec;
             break;
         }
         else if (ryanNewVec[i] < result[i]) {
             break;  // 기존 result가 더 우선이므로 break
         }
     }
 }

 int CompareVec(const vector<int>& apeach, vector<int> ryan)
 {
     int used = 0;
     for (int x : ryan) used += x;
     if (used < N)
         ryan[10] += (N - used);  // 남은 화살 0점에 몰아줌

     int apeachSum = 0;
     int ryanSum = 0;
     for (int i = 0; i < 11; i++)
     {
         if (apeach[i] == 0 && ryan[i] == 0) continue;

         if (apeach[i] >= ryan[i]) apeachSum += (10 - i);
         else ryanSum += (10 - i);
     }
     return ryanSum - apeachSum;
 }

 void RecapturePoint(const vector<int>& apeachVec, vector<int> ryanVec, int nowIdx, int nowCount)
 {
     // 0. 현재 인덱스가 마지막이면 그냥 반환
     if (nowIdx == 11) return;

     // 1. 현재 벡터가 result보다 더 큰 차이가 있다면 저장
     int nowDiff = CompareVec(apeachVec, ryanVec);
     if (nowDiff > maxDiff)
     {
         result = ryanVec;
         maxDiff = nowDiff;
     }
     // 1-1. 만약 차이가 동일하다면 result에 더 작은 점수에 더 많은 투자를 한 벡터로 저장
     else if (nowDiff == maxDiff)
     {
         // 가장 낮은 벡터 저장
         SaveSmallValueVec(ryanVec);
     }


     for (int curr = nowIdx; curr < 11; curr++)
     {
         int updatePoint = apeachVec[curr] + 1;
         int currPoint = ryanVec[curr];

         if (nowCount + updatePoint <= N)
         {
             ryanVec[curr] = updatePoint;
             RecapturePoint(apeachVec, ryanVec, curr + 1, nowCount + updatePoint);
             ryanVec[curr] = currPoint;
         }

     }
     
 }

 vector<int> solution(int n, vector<int> info)
 {
     vector<int> answer;
     vector<int> ryanStart(11, 0);
     maxDiff = 0;
     N = n;

     int apeachSum = 0;
     int ryanSum = 0;
     for (int i : info) apeachSum += i;

     RecapturePoint(info, ryanStart, 0, 0);
     answer = result;

     int remainN = n;
     // 결과값이 들어갔을 떄 확인
     if (answer.size() == 11)
     {
         // 결과값과 info의 차이가 0보다 크면 라이언의 승리로 라이언의 벡터 출력
         if (CompareVec(info, answer) > 0)
         {
             for (int nowN : answer)
                 remainN -= nowN;

             if (remainN > 0)
                 answer[10] += remainN;

             return answer;
         }
         // 동률이라면 -1
         else
             return { -1 };
     }
     // 져도 -1 출력
     else
         return { -1 };
 }
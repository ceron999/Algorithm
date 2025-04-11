/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/92342
/// ��� ��ȸ
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P51
{
    vector<int> result;
    int N;
    int maxDiff;

    void SaveSmallValueVec(const vector<int>& ryanNewVec)
    {
        if (result.empty()) {
            result = ryanNewVec;
            return;
        }

        for (int i = 10; i >= 0; --i)  // 0������
        {
            if (ryanNewVec[i] > result[i]) {
                result = ryanNewVec;
                break;
            }
            else if (ryanNewVec[i] < result[i]) {
                break;  // ���� result�� �� �켱�̹Ƿ� break
            }
        }
    }

    int CompareVec(const vector<int>& apeach, vector<int> ryan)
    {
        int used = 0;
        for (int x : ryan) used += x;
        if (used < N)
            ryan[10] += (N - used);  // ���� ȭ�� 0���� ������

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
        // 0. ���� �ε����� �������̸� �׳� ��ȯ
        if (nowIdx == 11) return;

        // 1. ���� ���Ͱ� result���� �� ū ���̰� �ִٸ� ����
        int nowDiff = CompareVec(apeachVec, ryanVec);
        if (nowDiff > maxDiff)
        {
            result = ryanVec;
            maxDiff = nowDiff;
        }
        // 1-1. ���� ���̰� �����ϴٸ� result�� �� ���� ������ �� ���� ���ڸ� �� ���ͷ� ����
        else if (nowDiff == maxDiff)
        {
            // ���� ���� ���� ����
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
        // ������� ���� �� Ȯ��
        if (answer.size() == 11)
        {
            // ������� info�� ���̰� 0���� ũ�� ���̾��� �¸��� ���̾��� ���� ���
            if (CompareVec(info, answer) > 0)
            {
                for (int nowN : answer)
                    remainN -= nowN;

                if (remainN > 0)
                    answer[10] += remainN;

                return answer;
            }
            // �����̶�� -1
            else
                return { -1 };
        }
        // ���� -1 ���
        else
            return { -1 };
    }
}

int main()
{
    vector<int> result2 = P51::solution(9, { 0,0,1,2,0,1,1,1,1,1,1 });

    for(int i : result2)
        cout << i << " ";
}
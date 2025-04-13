/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/70129
/// ���� ��ȯ �ݺ��ϱ�
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P65
{
    string ConvertIntToBinary(int nowSize)
    {
        string result;

        while (nowSize != 0)
        {
            string nowNum = to_string(nowSize % 2);
            result += nowNum;
            nowSize /= 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    int DeleteZero(string& curr)
    {
        int cnt = 0;
        for (int i = 0; i < curr.size(); )
        {
            if (curr[i] == '0')
            {
                curr.erase(curr.begin() + i);
                cnt++;
                continue;
            }
            i++;
        }
        return cnt;
    }

    vector<int> solution(string s) {
        vector<int> answer;
        string curr = s;

        int convertCnt = 0;
        int zeroCnt = 0;
        while (curr != "1")
        {
            // 1. 0 ����
            zeroCnt += DeleteZero(curr);

            // 2. curr�� ũ�⸦ ���������� ��ȯ
            int currSize = curr.size();
            curr = ConvertIntToBinary(currSize);
            convertCnt++;
        }

        answer.push_back(convertCnt);
        answer.push_back(zeroCnt);
        return answer;
    }
}

#include<bitset>
namespace P65_Answer
{
    vector<int> solution(string s) {
        int transforms = 0;
        int removedZeros = 0;
        //  s�� ��1���� �ɶ����� ��� �ݺ�
        while (s != "1") {
            transforms++;

            // '0' ������ ���� removedZeros�� ����
            removedZeros += count(s.begin(), s.end(), '0');

            // '1' ������ ����, �̸� �������� ��ȯ
            int onesCount = count(s.begin(), s.end(), '1');
            s = bitset<32>(onesCount).to_string();
            s = s.substr(s.find('1'));
        }

        return { transforms, removedZeros };
    }
}

//int main()
//{
//    vector<int> result = P65::solution("110010101001");
//    for(int i : result)
//        cout << i << " ";
//}
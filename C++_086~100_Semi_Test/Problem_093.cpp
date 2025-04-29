/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/92335
/// k진수 소수 개수 구하기
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace P93
{
    string Convert_Base_K(int defaultNum, int k)
    {
        string result;

        while (defaultNum > 0)
        {
            char num = (defaultNum % k) + '0';

            result.push_back(num);
            defaultNum /= k;
        }

        reverse(result.begin(), result.end());

        return result;
    }

    bool IsPrime(string numString)
    {
        long long num = stoll(numString);
        int sqrtNum = sqrt(num);

        for (int i = 2; i < sqrtNum; i++)
        {
            if (num % i == 0)
                return false;
        }

        return true;
    }

    vector<string> SplitNum(string nowNum)
    {
        vector<string> numVector;

        stringstream ss(nowNum);
        string token;

        while (getline(ss, token, '0'))
        {
            if (token == "1" || token == "")
                continue;
            numVector.push_back(token);
        }

        return numVector;
    }

    int solution(int n, int k) 
    {
        int answer = 0;

        string convertNum = Convert_Base_K(n, k);

        vector<string> splitNumVector = SplitNum(convertNum);

        for (string nowNum : splitNumVector)
        {
            if (IsPrime(nowNum))
                answer++;
        }

        return answer;
    }
}

//int main()
//{
//    //int result = P93::solution(437674, 3);
//    int result = P93::solution(110011, 10);
//
//		cout << result << " ";
//}
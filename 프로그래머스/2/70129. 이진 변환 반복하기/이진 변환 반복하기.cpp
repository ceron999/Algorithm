#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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
        // 1. 0 제거
        zeroCnt += DeleteZero(curr);

        // 2. curr의 크기를 이진법으로 변환
        int currSize = curr.size();
        curr = ConvertIntToBinary(currSize);
        convertCnt++;
    }

    answer.push_back(convertCnt);
    answer.push_back(zeroCnt);
    return answer;
}
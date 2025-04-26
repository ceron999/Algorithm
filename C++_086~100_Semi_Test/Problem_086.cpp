/// <summary>
/// 
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace P87
{
    // d, l, r, u 순서여야함
    string getDir(vector<int> dir, int k)
    {
        string result;

        char yDir = (dir[0] > 0) ? 'd' : 'u';
        for (int i = 0; i < abs(dir[0]); i++)
        {
            result.push_back(yDir);
        }

        char xDir = (dir[1] < 0) ? 'l' : 'r';
        for (int i = 0; i < abs(dir[1]); i++)
        {
            result.push_back(xDir);
        }

        sort(result.begin(), result.end());

        int remain = k - (abs(dir[0]) + abs(dir[1]));

        while (remain != 0)
        {
            
        }

        return result;
    }
    string solution(int n, int m, int x, int y, int r, int c, int k) {
        string answer = "";

        // (x로 이동할 거리, y로 이동할 거리)
        vector<int> dir = { (r - x), (c - y) };

        // 0. 결코 도달할 수 없으면 impossible을 반환
        if (abs(dir[0]) + abs(dir[1]) > k || (abs(dir[0]) + abs(dir[1]) - k) % 2 != 0)
            return "impossible";

        answer = getDir(dir, k);
        return answer;
    }
}

int main()
{
    string result = P87::solution(3,4,2,3,3,1,5);

        cout << result << " ";
}
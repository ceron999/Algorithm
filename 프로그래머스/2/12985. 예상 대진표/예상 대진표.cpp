#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    bool canSplit = true;

    while (true)
    {
        if (n / 2 >= a && n / 2 >= b)
        {
            n /= 2;
        }
        else if (n / 2 < a && n / 2 < b)
        {
            n /= 2;
            a -= n;
            b -= n;
        }
        else
            break;
    }

    while (n != 0)
    {
        n /= 2;
        answer++;
    }

    return answer - 1;
}
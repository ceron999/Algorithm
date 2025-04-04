#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    // 무조건 a < b이도록 구현
    if (b < a)
    {
        int temp = b;
        b = a;
        a = temp;
    }

    int answer = 1;
    int pivot = n / 2;
    n /= 2;
    while (n > 1)
    {
        // 1. a,b가 pivot 아래 있을 떄
        if (a <= pivot && b <= pivot)
        {
            n /= 2;
            pivot -= n;
        }
        // 2. a,b가 pivot 위에 있을 떄
        else if (a > pivot && b > pivot)
        {
            n /= 2;
            pivot += n;
        }

        // 3. a < pivot < b 순일떄
        else if (a <= pivot && b > pivot)
        {
            while (n > 1)
            {
                answer++;
                n /= 2;
            }
        }
    }

    return answer;
}
/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12985
/// 예상 대진표
/// </summary>

#include <iostream>
#include <string>

using namespace std;
namespace P30
{
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


    // 저자 풀이
    int solution2(int n, int a, int b)
    {
        int answer = 0;

        do {
            a = (a + 1) / 2;
            b = (b + 1) / 2;
            ++answer;
        } while (a != b);

        return answer;
    }
}

int main()
{
    int result = P30::solution(8,5,6);

        std::cout << result << " ";
}
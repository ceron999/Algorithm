/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12980
/// ������ �����̵�
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P68
{
    int solution(int n)
    {
        int ans = 0;

        while (n != 0)
        {
            if (n % 2 != 0)
            {
                ans++;
                n--;
            }
            else
            {
                n /= 2;
            }
        }

        return ans;
    }
}

//int main()
//{
//    int result = P68::solution(6);
//
//        cout << result << " ";
//}
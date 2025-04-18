/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/12945
/// 피보나치 수열
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P73
{
    int solution(int n) {
        vector<int> fib = { 0, 1 }; // fib(0) = 0, fib(1) = 1
        for (int i = 2; i <= n; ++i) {
            fib.push_back((fib[i - 1] + fib[i - 2]) % 1234567);
        }
        return fib[n];
    }
}

//int main()
//{
//    int result = P73::solution(100);
//
//        cout << result << " ";
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace p73
{
    int solution(int n) {
        int answer = 0;

        vector<int> fib = { 0,1 };

        for (int i = 2; i <= n; i++)
        {
            fib.push_back((fib[i - 2] + fib[i - 1]) % 1234567);
        }

        return fib[n];
    }

}
//void print(vector<int> vec)
//{
//    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
//    cout << endl;
//}

int main()
{
    int i = p73::solution(5);
    cout << i;
}
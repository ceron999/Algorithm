
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace p30
{
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

}
//void print(vector<int> vec)
//{
//    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
//    cout << endl;
//}

//int main()
//{
//
//    int i = p30::solution(8,4,7);
//
//    cout << i;
//}
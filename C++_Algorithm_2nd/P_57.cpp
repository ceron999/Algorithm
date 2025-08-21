
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace p57
{
    long long solution(long long n) {
        long long answer = 0;

        vector<int> nVector;

        while (n != 0)
        {
            nVector.push_back(n % 10);
            n /= 10;
        }

        sort(nVector.begin(), nVector.end(), [](const auto& a, const auto& b)
            {
                return a > b;
            });
        
        while (!nVector.empty())
        {
            answer *= 10;
            answer += nVector[0];

            nVector.erase(nVector.begin());
        }

        return answer;
    }

    long long solution2(long long n) {
        long long answer = 0;

        string s = to_string(n);

        sort(s.rbegin(), s.rend());
        return stoll(s);
    }

}
//void print(vector<int> vec)
//{
//    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
//    cout << endl;
//}
//
//int main()
//{
//    long long  input = 118372;
//
//    long long  i = p57::solution(input);
//    cout << i;
//    //print(i);
//}
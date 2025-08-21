
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace p74
{
    int solution(int n) {
        int answer = 0;

        // 1. n이 짝수일 경우 2를 n/2번 곱한다
        return answer;
    }

}
//void print(vector<int> vec)
//{
//    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
//    cout << endl;
//}

int main()
{
    vector<int> input = { 93, 30, 55 };
    vector<int> input2 = { 1, 30, 5 };

    int i = p74::solution(4);

    cout << i;
}
/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42746
/// 가장 큰 수
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace P59
{
    bool compareIntSize(const string& a, const string& b)
    {
            return a + b > b + a;
    }

    string solution(vector<int> numbers) 
    {
        string answer = "";
        vector<string> numStrings;
        for (int num : numbers) numStrings.push_back(to_string(num));
        
        sort(numStrings.begin(), numStrings.end(), compareIntSize);

        for (string num : numStrings)
            answer += num;

        if (answer[0] == '0') return to_string(0);

        return answer;
    }
}

//int main()
//{
//    string result2 = P59::solution({ 3, 30, 34, 5, 9 });
//
//        cout << result2 << " ";
//}
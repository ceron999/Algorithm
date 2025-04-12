/// <summary>
/// 저자 출제
/// 계수 정렬 구현
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
namespace P54
{
    string CountingSort(const string& input)
    {
        string result;
        map<char, int> charCount;

        for (char start = 'a'; start <= 'z'; start++)
            charCount[start] = 0;

        for (char c : input)
        {
            charCount[c]++;
        }

        for (char start = 'a'; start <= 'z'; start++)
        {
            if (charCount[start] != 0)
            {
                for (int i = 0; i < charCount[start]; i++)
                    result.push_back(start);
            }
        }

        return result;
    }

    string solution(string s)
    {
        string answer;

        answer = CountingSort(s);

        return answer;
    }
}

namespace P54_Answer
{
    string solution(string s) {
        // 알파벳 개수(26개)만큼 빈도수 배열 생성
        vector<int> counts(26, 0);

        // 문자열의 각 문자에 대한 빈도수를 빈도수 배열에 저장
        for (char c : s) {
            counts[c - 'a']++;
        }

        // 빈도수 배열을 순회하면서 정렬된 문자열을 생성
        string sorted_str = "";
        for (int i = 0; i < 26; i++) {
            sorted_str += string(counts[i], i + 'a');
        }

        return sorted_str;
    }
}

//int main()
//{
//    string result2 = P54::solution("hello");
//
//    for(char i : result2)
//        cout << i << " ";
//}
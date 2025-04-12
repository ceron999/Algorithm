/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/64065
/// 튜플
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
namespace P60
{
    // s -> string vector로 변환
    vector<string> SplitString(const string& nowString)
    {
        vector<string> tupleStringVec;

        // , 기준으로 나눈 string 중 가장 긴 string을 구한다
        stringstream ss(nowString);
        string token;

        while (getline(ss, token, '}'))
        {
            if (token[0] == ',')
                token.erase(token.begin());

            // { 제거
            token.erase(token.begin());
            tupleStringVec.push_back(token);
        }

        return tupleStringVec;
    }

    vector<vector<int>> ConvertStringToInt(const vector<string>& stringVec)
    {
        vector<vector<int>> tupleVec;   // string을 배열로 변환하여 저장한 벡터

        stringstream stringToIntParser;
        string token;

        for (string nowStringVec : stringVec)
        {
            vector<int> nowVec;

            stringToIntParser.clear();
            stringToIntParser.str(nowStringVec);

            // 현재 string을 배열로 변환
            while (getline(stringToIntParser, token, ','))
            {
                nowVec.push_back(stoi(token));
            }

            tupleVec.push_back(nowVec);
        }

        // 크기를 작은 순서대로 정렬
        sort(tupleVec.begin(), tupleVec.end(), [](const vector<int>& a, const vector<int>& b)
            {
                return a.size() < b.size();
            });

        return tupleVec;
    }

    vector<int> solution(string s) 
    {
        vector<int> answer;
        s.erase(s.begin());
        s.erase(s.end() - 1);

        // s -> string Vec으로 변환
        vector<string> tupleStringVec = SplitString(s);

        // 이제 int를 원소로 가진 벡터로 변환(이제 사용 가능)
        vector<vector<int>> tupleVec = ConvertStringToInt(tupleStringVec);

        // a1부터 차례대로 삽입(중복제거)
        unordered_set<int> result;
        for (vector<int> nowTuple : tupleVec)
        {
            for (int i : nowTuple)
            {
                if (result.find(i) == result.end())
                {
                    result.insert(i);
                    answer.push_back(i);
                }
            }
        }
        return answer;
    }
}

namespace P60_Answer
{
    int counts[100001] = {};

    void updateCounts(const string& s) {
        string numStr;
        // 인자로 받은 문자열을 순회
        for (char ch : s) {
            // 현재 문자가 숫자인 경우
            if (isdigit(ch)) {
                numStr += ch;
                // 현재 문자가 숫자가 아닌 경우
            }
            else {
                if (!numStr.empty()) {
                    // 계수정렬을 하기 위해 각 숫자의 개수를 저장 
                    counts[stoi(numStr)]++;
                    numStr.clear();
                }
            }
        }
    }

    vector<int> solution(string s) {
        vector<int> answer;
        // 집합이 담긴 문자열의 각 원소를 계수정렬
        updateCounts(s);

        vector<pair<int, int>> freqPairs;
        for (int i = 1; i <= 100000; i++) {
            // 집합에 있는 원소인 경우 (개수, 값) 형식으로 푸시
            if (counts[i] > 0) {
                freqPairs.push_back({ counts[i], i });
            }
        }

        // 각 원소의 개수를 기준으로 내림차순 정렬
        sort(freqPairs.rbegin(), freqPairs.rend());

        // 원소의 개수로 내림차순 정렬된 벡터를 순회하며 원소를 푸시
        for (const auto& p : freqPairs) {
            answer.push_back(p.second);
        }

        return answer;
    }
}

int main()
{
    vector<int> result2 = P60::solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");

    for(int i : result2)
        cout << i << " ";
}
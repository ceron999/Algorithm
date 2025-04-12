#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;

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
/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/64065
/// Ʃ��
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
    // s -> string vector�� ��ȯ
    vector<string> SplitString(const string& nowString)
    {
        vector<string> tupleStringVec;

        // , �������� ���� string �� ���� �� string�� ���Ѵ�
        stringstream ss(nowString);
        string token;

        while (getline(ss, token, '}'))
        {
            if (token[0] == ',')
                token.erase(token.begin());

            // { ����
            token.erase(token.begin());
            tupleStringVec.push_back(token);
        }

        return tupleStringVec;
    }

    vector<vector<int>> ConvertStringToInt(const vector<string>& stringVec)
    {
        vector<vector<int>> tupleVec;   // string�� �迭�� ��ȯ�Ͽ� ������ ����

        stringstream stringToIntParser;
        string token;

        for (string nowStringVec : stringVec)
        {
            vector<int> nowVec;

            stringToIntParser.clear();
            stringToIntParser.str(nowStringVec);

            // ���� string�� �迭�� ��ȯ
            while (getline(stringToIntParser, token, ','))
            {
                nowVec.push_back(stoi(token));
            }

            tupleVec.push_back(nowVec);
        }

        // ũ�⸦ ���� ������� ����
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

        // s -> string Vec���� ��ȯ
        vector<string> tupleStringVec = SplitString(s);

        // ���� int�� ���ҷ� ���� ���ͷ� ��ȯ(���� ��� ����)
        vector<vector<int>> tupleVec = ConvertStringToInt(tupleStringVec);

        // a1���� ���ʴ�� ����(�ߺ�����)
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
        // ���ڷ� ���� ���ڿ��� ��ȸ
        for (char ch : s) {
            // ���� ���ڰ� ������ ���
            if (isdigit(ch)) {
                numStr += ch;
                // ���� ���ڰ� ���ڰ� �ƴ� ���
            }
            else {
                if (!numStr.empty()) {
                    // ��������� �ϱ� ���� �� ������ ������ ���� 
                    counts[stoi(numStr)]++;
                    numStr.clear();
                }
            }
        }
    }

    vector<int> solution(string s) {
        vector<int> answer;
        // ������ ��� ���ڿ��� �� ���Ҹ� �������
        updateCounts(s);

        vector<pair<int, int>> freqPairs;
        for (int i = 1; i <= 100000; i++) {
            // ���տ� �ִ� ������ ��� (����, ��) �������� Ǫ��
            if (counts[i] > 0) {
                freqPairs.push_back({ counts[i], i });
            }
        }

        // �� ������ ������ �������� �������� ����
        sort(freqPairs.rbegin(), freqPairs.rend());

        // ������ ������ �������� ���ĵ� ���͸� ��ȸ�ϸ� ���Ҹ� Ǫ��
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
/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/64065
/// Ʃ��
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
namespace P60
{

    vector<int> solution(string s) 
    {
        vector<int> answer;
        s.erase(s.begin());
        s.erase(s.end() - 1);

        string maxTuple = "";

        // , �������� ���� string �� ���� �� string�� ���Ѵ�
        stringstream ss(s);
        string token;
        while (getline(ss, token, '}'))
        {
            if (token[0] == ',') token.erase(token.begin());
            if (maxTuple.size() < token.size()) maxTuple = token;
        }

        // ��ȣ ����
        maxTuple.erase(maxTuple.begin());
        ss.clear();
        ss.str(maxTuple);
        while (getline(ss, token, ','))
        {
            answer.push_back(stoi(token));
        }

        return answer;
    }
}

int main()
{
    vector<int> result2 = P60::solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");

    for(int i : result2)
        cout << i << " ";
}
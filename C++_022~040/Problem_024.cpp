/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42888
/// 오픈 채팅방
/// 
/// 
/// </summary>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
namespace P24
{
    vector<pair<string, string>> log;
    unordered_map<string, string> userInfo; // <아이디, 닉네임>
    
    vector<string> SplitRecord(const string& inputRecord)
    {
        vector<string> result;
        stringstream ss(inputRecord);
        string item;

        while (getline(ss, item, ' '))
        {
            result.push_back(item);
        }

        return result;
    }

    void UpdateInfo(vector<string> inputRecord)
    {
        if (inputRecord[0] == "Enter")
        {
            auto it = userInfo.find(inputRecord[1]);

            // info 업데이트
            if (it == userInfo.end())
                userInfo.insert({ inputRecord[1], inputRecord[2] });
            else
                userInfo[inputRecord[1]] = inputRecord[2];

            log.push_back({ inputRecord[1], "님이 들어왔습니다." });
        }
        else if (inputRecord[0] == "Leave")
        {
            log.push_back({ inputRecord[1], "님이 나갔습니다." });
        }
        else if (inputRecord[0] == "Change")
        {
            userInfo[inputRecord[1]] = inputRecord[2];
        }
    }

    vector<string> solution(vector<string> record) 
    {
        vector<string> answer;


        for (const string &nowRecord : record)
        {
            // 명령, id, 닉 순서로 변경하여 가져옴
            vector<string> splitVector = SplitRecord(nowRecord);
            UpdateInfo(splitVector);
        }

        for (auto nowLog : log)
        {
            string nowNickName = userInfo[nowLog.first];
            string nowLogBack = nowLog.second;

            answer.push_back(nowNickName + nowLogBack);
        }

        return answer;
    }
}

//int main()
//{
//    vector<string> result = P24::solution
//    ({ 
//        "Enter uid1234 Muzi", 
//        "Enter uid4567 Prodo",
//        "Leave uid1234",
//        "Enter uid1234 Prodo",
//        "Change uid4567 Ryan" 
//    });
//
//    for (string i : result)
//        cout << i << endl;
//}
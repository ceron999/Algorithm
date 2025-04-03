#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, unordered_set<string>> userInfo; // <유저, 신고한 유저 리스트>
unordered_map<string, int> reportCountInfo;     // <유저, 신고당한 횟수
unordered_set<string> reportOverKList;                 // k 이상 신고당한 유저

void UpdateReportInfo(const string &nowReport, int reportMaxNum)
{

    vector<string> report;
    stringstream ss(nowReport);

    // 1. report 분할
    string userId, reportedId;
    ss >> userId >> reportedId;

    // 2. 신고한 사람에 reportedId 추가 , reportedId에 신고 카운트 ++
    if (userInfo[userId].find(reportedId) == userInfo[userId].end())
    {
        userInfo[userId].insert(reportedId);
        reportCountInfo[reportedId]++;

        // 3. 신고 카운트가 K 이상이면 신고 누적 리스트에 추가
        if (reportCountInfo[reportedId] >= reportMaxNum)
            reportOverKList.insert(reportedId);
    }
}

int GetReportedIdCount(string searchId)
{
    int count = 0;

    for (string reportedId : reportOverKList)
    {
        if (userInfo[searchId].find(reportedId) != userInfo[searchId].end())
            count++;
    }

    return count;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    for (string name : id_list)
    {
        userInfo[name];
    }

    // 신고당한 report 데이터를 userInfo, reportCountInfo, reportOverKList에 추가
    for (string nowReport : report)
    {
        UpdateReportInfo(nowReport, k);
    }

    // k번 이상 신고당한 사람들을 userInfo[유저아이디]에 얼마나 있는지 세고 개수 반환
    for (string searchId : id_list)
    {
        int nowCount = GetReportedIdCount(searchId);
        answer.push_back(nowCount);
    }

    return answer;
}
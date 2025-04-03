/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/92334
/// �Ű� ��� �ޱ�
/// 
/// �����ߴ� ����
/// unordered_set<string> reportOverKList;��
/// vector<string> ���� �����Ͽ� �Ű���� ��� �ߺ��� �������
/// 
/// ����
/// <�Ű���ѻ��, �Ű��� ��� ����Ʈ> �̷��� ���� Ǯ��
/// </summary>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
namespace P26
{
    unordered_map<string, unordered_set<string>> userInfo; // <����, �Ű��� ���� ����Ʈ>
    unordered_map<string, int> reportCountInfo;     // <����, �Ű���� Ƚ��
    unordered_set<string> reportOverKList;                 // k �̻� �Ű���� ����

    void UpdateReportInfo(const string &nowReport, int reportMaxNum)
    {

        vector<string> report;
        stringstream ss(nowReport);

        // 1. report ����
        string userId, reportedId;
        ss >> userId >> reportedId;

        // 2. �Ű��� ����� reportedId �߰� , reportedId�� �Ű� ī��Ʈ ++
        if (userInfo[userId].find(reportedId) == userInfo[userId].end())
        {
            userInfo[userId].insert(reportedId);
            reportCountInfo[reportedId]++;

            // 3. �Ű� ī��Ʈ�� K �̻��̸� �Ű� ���� ����Ʈ�� �߰�
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

        // �Ű���� report �����͸� userInfo, reportCountInfo, reportOverKList�� �߰�
        for (string nowReport : report)
        {
            UpdateReportInfo(nowReport, k);
        }

        // k�� �̻� �Ű���� ������� userInfo[�������̵�]�� �󸶳� �ִ��� ���� ���� ��ȯ
        for (string searchId : id_list)
        {
            int nowCount = GetReportedIdCount(searchId);
            answer.push_back(nowCount);
        }

        return answer;
    }
}

//int main()
//{
//    vector<int> result = P26::solution({ "muzi", "frodo", "apeach", "neo" },
//        { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }, 2);
//    for (int i : result)
//        cout << i << " ";
//}
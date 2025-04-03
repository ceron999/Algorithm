/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/72411
/// �޴� ������
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>


using namespace std;
namespace P27
{
    map<string, int> availableAllCourseMap;     // ������ �ڽ�
    set<string> availableCourseSet;

    void Combination(string order, string dst, int depth)
    {
        if (dst.size() != depth)
        {
            for (int i = 0; i < order.size(); i++)
                Combination(order.substr(i + 1), dst + order[i], depth);
        }
        else
            availableAllCourseMap[dst]++;
    }

    // avail
    void AddNewCourse(int size)
    {
        // availableAllCourseMap���� ũ�Ⱑ size �� �͸� vector�� �ű�
        vector<pair<string, int>> nowCourses;
        for (auto it = availableAllCourseMap.begin(); it != availableAllCourseMap.end(); ++it)
        {
            if (it->first.size() == size)
                nowCourses.push_back(*it);
        }

        if (nowCourses.empty()) return;

        // �ڽ��� ���õ� ������ŭ ����
        sort(nowCourses.begin(), nowCourses.end(), 
            [](const pair<string, int>& a, const pair<string, int>& b) 
            {
                return a.second > b.second;
            });

        // 2���� ������ ����
        if (nowCourses[0].second < 2) return;  

        int maxNum = nowCourses[0].second;
        for (auto& nowCourse : nowCourses)
        {
            if (nowCourse.second == maxNum)
                availableCourseSet.insert(nowCourse.first);
            else
                break;
        }
    }

    vector<string> solution(vector<string> orders, vector<int> course) 
    {
        vector<string> answer;

        // ��� ���� ã��
        for (string nowOrder : orders)
        {
            sort(nowOrder.begin(), nowOrder.end());
            for (int courseSize : course)
            {
                Combination(nowOrder, "", courseSize);
            }
        }

        for (int courseSize : course)
        {
            AddNewCourse(courseSize);
        }

        for (string course : availableCourseSet)
            answer.push_back(course);

        return answer;
    }
}

int main()
{
    vector<string> result = P27::solution({ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2,3,5 });
    for (string i : result)
        cout << i << " ";
}
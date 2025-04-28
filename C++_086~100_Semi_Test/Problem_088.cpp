/// <summary>
/// 
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;
namespace P88
{
    class DateTime
    {
    public:
        int year = -1;
        int month = -1;
        int day = -1;

        DateTime(string date)
        {
            stringstream ss(date);
            string token;

            int count = 0;
            while(getline(ss, token,'.'))
            {
                switch (count)
                {
                case 0:
                    year = stoi(token);
                    count++;
                    break;
                case 1:
                    month = stoi(token);
                    count++;
                    break;
                case 2:
                    day = stoi(token);
                    count++;
                    break;
                }
            }
        }

        void UpdateDate(int duration)
        {
            month += duration;
            day--;

            if (day == 0)
            {
                day = 28;
                month--;
            }

            while (month > 12)
            {
                month -= 12;
                year++;
            }

        }

        
    };
    bool operator < (const DateTime& a, const DateTime& b)
    {
        if (a.year != b.year)
        {
            return a.year < b.year;
        }
        else if (a.month != b.month)
        {
            return a.month < b.month;
        }
        else if (a.day != b.day)
        {
            return a.day < b.day;
        }
        else
            return false;
    }
    vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
        vector<int> answer;

        DateTime nowDate(today);
        unordered_map<string, int> termMap;
        vector<DateTime> endDateVector;

        // {타입, 기간} 정리
        for (string nowTerm : terms)
        {
            stringstream ss(nowTerm);
            string nowType;
            string nowDuration;

            ss >> nowType >> nowDuration;
            termMap.insert({ nowType, stoi(nowDuration) });
        }

        for (string nowPrivacy : privacies)
        {
            stringstream ss(nowPrivacy);
            string nowDateString;
            string nowType;

            ss >> nowDateString >> nowType;

            DateTime nowDate(nowDateString);

            nowDate.UpdateDate(termMap[nowType]);

            endDateVector.push_back(nowDate);
        }

        for (int i =0; i< endDateVector.size(); i++)
        {
            if (endDateVector[i] < nowDate)
            {
                answer.push_back(i + 1);
            }
        }

        return answer;
    }
}

//int main()
//{
//    string today = "2022.05.19";
//    vector<string> terms = { "A 6", "B 12", "C 3" };
//    vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };
//	vector<int> result = P88::solution(today, terms, privacies);
//
//	for (int i : result)
//		cout << i << " ";
//}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "";
    queue<string> card1Queue;
    queue<string> card2Queue;

    for (string s : cards1)
    {
        card1Queue.push(s);
    }
    for (string s : cards2)
    {
        card2Queue.push(s);
    }

    int nowIndex = 0;
    while(goal.size() != nowIndex)
    {
        if (card1Queue.size() > 0 && card1Queue.front() == goal[nowIndex])
        {
            card1Queue.pop();
            nowIndex++;
        }
        else if (card2Queue.size() > 0 && card2Queue.front() == goal[nowIndex])
        {
            card2Queue.pop();
            nowIndex++;
        }
        else
            break;
    }
    answer = (goal.size() == nowIndex) ? "Yes" : "No";
    return answer;
}
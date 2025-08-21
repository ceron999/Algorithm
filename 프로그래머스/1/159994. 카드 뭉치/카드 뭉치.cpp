#include <string>
#include <vector>
#include <queue>

using namespace std;
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";

    bool isAvailable = true;

    queue<string> cardQueue1;
    queue<string> cardQueue2;
    queue<string> goalQueue;

    for (string s : cards1) cardQueue1.push(s);
    for (string s : cards2) cardQueue2.push(s);
    for (string s : goal) goalQueue.push(s);

    while (!goalQueue.empty())
    {
        if (!cardQueue1.empty() && goalQueue.front() == cardQueue1.front())
        {
            goalQueue.pop();
            cardQueue1.pop();
        }
        else if (!cardQueue2.empty() && goalQueue.front() == cardQueue2.front())
        {
            goalQueue.pop();
            cardQueue2.pop();
        }
        else
        {
            isAvailable = false;
            break;
        }
    }

    return isAvailable ? "Yes" : "No";
}
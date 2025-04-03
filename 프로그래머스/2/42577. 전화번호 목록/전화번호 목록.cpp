#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) 
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        int numSIze = phone_book[i].size();
        if (phone_book[i + 1].substr(0, numSIze) == phone_book[i])
        {
            return false;
        }
    }

    return true;
}
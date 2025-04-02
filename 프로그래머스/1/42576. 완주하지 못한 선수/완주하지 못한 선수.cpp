#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long hashing(const string &s)
{
    long long result = 0;
    const int p = 31;
    const long long m = 100007;
    
    for (char c : s)
    {
        result += (result * p + c) % m;
    }
    return result;
}

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";

    unordered_map<long long, int> hashMap;
    for (string s : completion)
    {
        long long hashIndex = hashing(s);

        auto it = hashMap.find(hashIndex);
        if (it != hashMap.end())
        {
            it->second += 1;
        }
        else
        {
            hashMap.insert({ hashIndex, 1 });
        }
    }

    for (string searchString : participant)
    {
        long long hashIndex = hashing(searchString);
        auto it = hashMap.find(hashIndex);

        if (it == hashMap.end() || it->second == 0)
        {
            answer = searchString;
            break;
        }
        else
        {
            it->second -= 1;
        }
    }

    return answer;
}
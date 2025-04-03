/// <summary>
/// 
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;
namespace P22
{
    bool solution(vector<string> phone_book) 
    {
        bool answer = true;
        // string�� sort�ϸ� �պκ��� ����� �༮�鳢�� ¦��������.
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
}

//int main()
//{
//    bool result = P22::solution({ "119", "97674223", "1195524421" });
//
//    
//        cout << result << " ";
//}
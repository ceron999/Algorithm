#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;

    map<string, int> needMap;
    int sum = 0;    // 원하는 물건 개수의 총합
    for (int i : number)
        sum += i;
    int saleMapsSize = discount.size() - sum + 1;
    vector<map<string, int>> saleMaps(saleMapsSize);

    // 원하는 물건, 개수를 짝지어 매핑
    for (int i = 0; i < want.size(); i++)
    {
        needMap.insert({ want[i], number[i] });
    }

    // discount를 sum 크기로 쪼개 saleMaps에 삽입
    // i일에 결제하면 saleMaps[i]에 들어있는 물건들을 할인받을 수 있음
    for (int i = 0; i < saleMapsSize;i++)
    {
        for (int sumIndex = 0; sumIndex < sum; sumIndex++)
        {
            auto it = saleMaps[i].find(discount[i+ sumIndex]);

            if (it == saleMaps[i].end())
            {
                saleMaps[i].insert({ discount[i + sumIndex] , 1 });
            }
            else
            {
                it->second++;
            }
        }
    }

    for (auto nowSaleMap : saleMaps)
    {
        if (nowSaleMap == needMap)
            answer++;
    }

    return answer;
}
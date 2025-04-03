/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/131127
/// 할인 행사
/// 
/// for (int j = i; j < 10 + i; j++)
///     discount_10d[discount[j]]++;
/// 이렇게 value 없이 초기화하면 0으로 초기화된대여
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;
namespace P23
{
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

    int solution2(vector<string> want, vector<int> number, vector<string> discount) {
        int answer = 0;

        unordered_map<string, int> wantMap;
        // want를 키로  number를 값으로 해서 wantMap을 선언
        for (int i = 0; i < want.size(); i++)
            wantMap[want[i]] = number[i];


        for (int i = 0; i < discount.size() - 9; i++) {
            //  i일 회원가입 시, 할인받을 수 있는 품목을 키로, 개수를 값으로 해서  discount_10d 선언
            unordered_map<string, int> discount_10d;

            //   각 할인하는 품목을 키로  개수를 저장
            
            for (int j = i; j < 10 + i; j++)
                discount_10d[discount[j]]++;

            //  할인하는 상품의 품목및 개수가 원하는 상품의 품목 및 개수와 일치하면 카운트 증가
            if (wantMap == discount_10d) answer++;
        }

        return answer;
    }
}

//int main()
//{
//    int result = P23::solution({ "banana", "apple", "rice", "pork", "pot" },
//        { 3, 2, 2, 2, 1 },
//        { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", 
//        "banana", "pork", "rice", "pot", "banana", "apple", "banana" });
//    
//        cout << result << " ";
//}
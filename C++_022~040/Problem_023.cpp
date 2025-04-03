/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/131127
/// ���� ���
/// 
/// for (int j = i; j < 10 + i; j++)
///     discount_10d[discount[j]]++;
/// �̷��� value ���� �ʱ�ȭ�ϸ� 0���� �ʱ�ȭ�ȴ뿩
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
        int sum = 0;    // ���ϴ� ���� ������ ����
        for (int i : number)
            sum += i;
        int saleMapsSize = discount.size() - sum + 1;
        vector<map<string, int>> saleMaps(saleMapsSize);

        // ���ϴ� ����, ������ ¦���� ����
        for (int i = 0; i < want.size(); i++)
        {
            needMap.insert({ want[i], number[i] });
        }

        // discount�� sum ũ��� �ɰ� saleMaps�� ����
        // i�Ͽ� �����ϸ� saleMaps[i]�� ����ִ� ���ǵ��� ���ι��� �� ����
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
        // want�� Ű��  number�� ������ �ؼ� wantMap�� ����
        for (int i = 0; i < want.size(); i++)
            wantMap[want[i]] = number[i];


        for (int i = 0; i < discount.size() - 9; i++) {
            //  i�� ȸ������ ��, ���ι��� �� �ִ� ǰ���� Ű��, ������ ������ �ؼ�  discount_10d ����
            unordered_map<string, int> discount_10d;

            //   �� �����ϴ� ǰ���� Ű��  ������ ����
            
            for (int j = i; j < 10 + i; j++)
                discount_10d[discount[j]]++;

            //  �����ϴ� ��ǰ�� ǰ��� ������ ���ϴ� ��ǰ�� ǰ�� �� ������ ��ġ�ϸ� ī��Ʈ ����
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
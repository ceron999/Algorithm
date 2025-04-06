/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/1845
/// ���ϸ�
/// 
/// ������ �������� ���ʿ��� map�� ���
/// �ܼ��� unordered_set���� �ߺ� ���Ÿ� �ϰ� �ش� ������ �󸶳� �ִ����� �߿����� �ʾ���
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
namespace P34
{

    int solution(vector<int> nums)
    {
        unordered_map<int, int> ponketmonMap;
        int getSize = nums.size() / 2;
        for (int i : nums)
        {
            ponketmonMap[i]++;
        }


        int answer =  (ponketmonMap.size() > getSize) ? getSize : ponketmonMap.size();
        return answer;
    }
}

//int main()
//{
//    int result = P34::solution({ 3,1,2,3 });
//
//        cout << result << " ";
//}
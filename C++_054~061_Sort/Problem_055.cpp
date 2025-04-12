/// <summary>
/// 저자 출제
/// 정렬이 완료된 두 배열 합치기
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P55
{
    vector<int> MergeSort(const vector<int>& arr1, const vector<int>& arr2)
    {
        vector<int> result;

        auto arr1Ptr = arr1.begin();
        auto arr2Ptr = arr2.begin();

        while (arr1Ptr != arr1.end() || arr2Ptr != arr2.end())
        {
            if (arr1Ptr != arr1.end() && arr2Ptr != arr2.end())
            {
                if (*arr1Ptr > *arr2Ptr)
                {
                    result.push_back(*arr2Ptr);
                    arr2Ptr++;
                }
                else if (*arr1Ptr < *arr2Ptr)
                {
                    result.push_back(*arr1Ptr);
                    arr1Ptr++;
                }
                else
                {
                    result.push_back(*arr1Ptr);
                    result.push_back(*arr2Ptr);
                    arr1Ptr++;
                    arr2Ptr++;
                }
            }
            else
            {
                if (arr1Ptr != arr1.end())
                {
                    result.push_back(*arr1Ptr);
                    arr1Ptr++;
                }
                else if (arr2Ptr != arr2.end())
                {
                    result.push_back(*arr2Ptr);
                    arr2Ptr++;
                }
            }
           
        }

        return result;
    }
    vector<int> solution(vector<int> arr1, vector<int> arr2)
    {
        vector<int> answer;
        answer = MergeSort(arr1, arr2);
        return answer;
    }
}

//int main()
//{
//    vector<int> result2 = P55::solution({1,3,5}, {2,4,6});
//
//    for(int i : result2)
//        cout << i << " ";
//}
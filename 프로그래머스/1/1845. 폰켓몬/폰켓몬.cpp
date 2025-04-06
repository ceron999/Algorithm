#include <vector>
#include <unordered_map>
using namespace std;

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
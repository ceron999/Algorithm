#include <string>
#include <vector>
#include <algorithm>

using namespace std;

  bool compareIntSize(const string& a, const string& b)
{
        return a + b > b+ a;
}

 string solution(vector<int> numbers) 
 {
     string answer = "";
     vector<string> numStrings;
     for (int num : numbers) numStrings.push_back(to_string(num));
     
     sort(numStrings.begin(), numStrings.end(), compareIntSize);

     for (string num : numStrings) answer += num;

     if (answer[0] == '0') return to_string(0);

     return answer;
 }
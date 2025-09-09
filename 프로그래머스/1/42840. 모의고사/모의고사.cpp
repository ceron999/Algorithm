#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> pattern_1 = {1,2,3,4,5};
    vector<int> pattern_2 = {2,1,2,3,2,4,2,5};
    vector<int> pattern_3 = {3,3,1,1,2,2,4,4,5,5};
    
    vector<int> correctCount(3);
    
    for(int i=0;i< answers.size();i++)
    {
        if(answers[i] == pattern_1[i%pattern_1.size()]) correctCount[0]++;
        if(answers[i] == pattern_2[i%pattern_2.size()]) correctCount[1]++;
        if(answers[i] == pattern_3[i%pattern_3.size()]) correctCount[2]++;
    }
    
    int maxValue = *max_element(correctCount.begin(), correctCount.end());
    
    for(int i =0; i< correctCount.size();i++)
    {
        if(correctCount[i] == maxValue)
            answer.push_back(i + 1);
    }
    
    return answer;
}
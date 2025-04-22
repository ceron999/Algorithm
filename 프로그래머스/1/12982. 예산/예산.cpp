#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

 int solution(vector<int> d, int budget) 
 {
     int answer = 0;

     sort(d.begin(), d.end(), [](const int& a, const int& b)
         {
             return a < b;
         });

     for (int nowD : d)
     {
         if (nowD <= budget)
         {
             budget -= nowD;
             answer++;
         }
         else
             break;
     }

     return answer;
 }
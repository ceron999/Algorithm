//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <stack>
//
//using namespace std;
//
//namespace p12
//{
//    
//    vector<int> solution(vector<int> prices) {
//        vector<int> answer(prices.size(), -1);
//
//        stack<int> stk;
//
//        for (int i =0; i< prices.size(); i++)
//        {
//            while (!stk.empty() && prices[stk.top()] > prices[i]) 
//            {
//                int j = stk.top(); 
//                stk.pop();
//                answer[j] = i - j; // 떨어지기까지 걸린 시간
//            }
//            stk.push(i);
//        }
//
//        int resultTime = 0;
//        for (int i =0; i<answer.size();i++)
//        {
//            if (answer[i] == -1)
//            {
//                answer[i] = resultTime;
//                resultTime++;
//
//                if(!stk.empty())
//                    stk.pop();
//            }
//            else
//            {
//                resultTime++;
//            }
//        }
//
//        reverse(answer.begin(), answer.end());
//        return answer;
//    }
//}
//
//void print(vector<int> vec)
//{
//    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
//    cout << endl;
//}
//
//int main()
//{
//    vector<int> input = { 1, 2, 3, 2, 3 };
//
//    vector<int> i = p12::solution(input);
//
//    print(i);
//}
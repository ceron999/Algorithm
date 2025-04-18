#include <string>
#include <vector>

using namespace std;

    int solution(int n) 
    {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);

        for (int i = 3; i <= n; i++)
        {
            int result = (dp[i - 2] + dp[i - 1]) % 1000000007;
            dp.push_back(result);
        }

        return dp[n];
    }

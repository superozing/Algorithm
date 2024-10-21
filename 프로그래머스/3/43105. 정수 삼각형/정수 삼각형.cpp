#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> tri) 
{
    int ans = 0;
    
    vector<vector<int>> dp = tri;
    
    // 삼각형 깊이가 1, 2인 경우의 예외처리가 필요해요.
    dp[1][0] += dp[0][0];
    dp[1][1] += dp[0][0];
    
    for (int i = 2; i < dp.size(); ++i) // 깊이
    {
        //cout << i << "층: ";
        for (int j = 0; j < dp[i].size(); ++j) // 넓이
        {
            // 무조건 아래로 내려갈 수록 커진다
            // 아 근데 비교를 해야 하긴 하네요.
            // 1. j == 0
            if (j == 0)
                dp[i][0] += dp[i - 1][0];
            // 2. j == dp[i].size() - 1
            else if (j == dp[i].size() - 1)
                dp[i][j] += dp[i - 1][j - 1];
            // 3. else
            else
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            
            ans = max(dp[i][j], ans);
        }
        //cout << endl;
    }

    return ans;
}
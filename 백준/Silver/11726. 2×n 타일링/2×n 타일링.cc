////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;


class Boj
{
private:
    int N; // 2*N 크기의 직사각형

public:
    void input()
    {
        cin >> N;
    }

    void progress()
    {
        vector<int> dp(N + 1);

        /*
        2*0 -> 0
        2*1 -> 1
        2*2 -> 2
        2*3 -> 3
        2*4 -> 음...
        */

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= N; ++i)
            dp[i] = dp[i - 2] + dp[i - 1] % 10007;
        
        cout << dp[N] % 10007;
    }

};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}

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
    int N;

    int dp[46]{};

public: 
    void input()
    {
        cin >> N;
        dp[0] = 0;
        dp[1] = 1;
    }

    void progress()
    {
        for (int i = 2; i <= N; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        cout << dp[N];
    }

};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}

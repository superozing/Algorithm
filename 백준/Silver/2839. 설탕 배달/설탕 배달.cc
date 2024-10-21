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

constexpr auto INF = 9999;

class Boj
{
private:
    int N; // 설탕 무게

public:
    void input()
    {
        cin >> N;
    }

    void progress()
    {
        vector<int> dp;
        if (N < 3 || (N < 5 && N != 3))
        {
            cout << -1;
            return;
        }

        dp.resize(N + 1, INF);

        dp[3] = 1;
        dp[5] = 1;

        for (int i = 6; i <= N; ++i)
        {
            dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
        }

        if (dp[N] < INF)
            cout << dp[N];
        else
            cout << -1;

        return;
    }

};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}

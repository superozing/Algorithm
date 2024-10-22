
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
    int N; // 동전 개수
    vector<int> coins; // 동전 가치

    int K; // 가치의 합 목표

public:
    void input()
    {
        cin >> N >> K;
        coins.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> coins[i];
    }

    void progress()
    {
        vector<int> dp(K + 1);

        //for (auto& it : coins)
        //    if (it <= K)
        //        ++dp[it];
        dp[0] = 1;
        for (auto& coin : coins)
            for (int i = coin; i <= K; ++i)
               dp[i] += dp[i - coin];

        cout << dp[K];
    }

};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}

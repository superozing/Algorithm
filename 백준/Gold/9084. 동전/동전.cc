//////////////////////////////////////////
// 동전
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

constexpr auto INF = 999999999;

class Boj
{
private:
    int T;

    int N; // 동전 개수
    vector<int> coins; // 동전들
    vector<int> dp;
    int M; // 목표 금액

public:
    void input()
    {
        cin >> T;
        dp.resize(10001);
    }

    void progress()
    {
        for (int t = 0; t < T; ++t)
        {
            for (int i = 0; i <= 10000; ++i)
                dp[i] = 0;

            cin >> N;
            coins.resize(N);
            for (int n = 0; n < N; ++n)
                cin >> coins[n];

            cin >> M;

            for (auto& coin : coins)
            {
                dp[coin]++;
                for (int i = coin; i < dp.size(); ++i)
                    dp[i] = dp[i - coin] + dp[i];
            }

            cout << dp[M] << endl;
        }
    }

};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}


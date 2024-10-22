//////////////////////////////////////////
// 평범한 배낭
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
    int N; // 물건의 개수
    int K; // 최대 무게

    vector<int> weight; // 물건의 무게
    vector<int> value; // 물건의 가치

public:
    void input()
    {
        cin >> N >> K;

        weight.resize(N + 1);
        value.resize(N + 1);

        for (int i = 1; i <= N; ++i)
        {
            cin >> weight[i];
            cin >> value[i];
        }
    }

    void progress()
    {
        // 해당 물건을 배낭에 넣는가?

        // 가방의 무게가 현재 내가 버틸 수 있는 무게보다 무거우면 배낭에 넣을 수 없다.
        // -> 현재의 K보다 물건의 무게 W가 작으면 배낭에 넣을 수 없다.
        // 물건을 넣었을 때의 가치 합이 이전 최대값보다 적다면 해당 물건을 넣을 필요가 없다.

        // 무게를 인덱스 기준으로 잡음
        vector<vector<int>> dp(N + 1, vector<int>(K + 1));

        // 무게dp는 순차적으로 물건 A까지 돌렸을 때 최대 가치
        // i: 물건
        // j: 현재 들고 있는 무게
        for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= K; ++j)
        {
            // 현재 무게가 물건의 무게보다는 커야 한다
            if (j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            // dp[i - 1][j] 이전까지의 최대 가치
            // dp[i - 1][j - weight[i]] + value[i] 무게를 넣은 가치
            else // 물건을 더 넣을 수 없다.
                dp[i][j] = dp[i - 1][j];
        }

        cout << dp[N][K];

    }
};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}


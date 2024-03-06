#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class BAEKJOON // 동전 2
{
public:
    int         N;      // 동전 개수 
    int         K;      // 목표 원

    vector<int> coins;

    vector<int> dp;     // dp[i] - i원일 때 최소 동전 개수 

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
};

void BAEKJOON::init()
{
    cin >> N >> K;

    coins.resize(N);

    // 가장 적은 개수를 구하기 위해서 초기 값을 가장 큰 값으로 만들어주어요.
    dp.resize(K + 1, 999999);

    dp[0] = 0;

    for (int i = 0; i < N; ++i)
        cin >> coins[i];
}


void BAEKJOON::progress()
{
    // dp[i - coin] + 1
    //      dp[i - coin]     => 현재 동전을 넣지 않았을 경우
    //      dp[i - coin] + 1 => 현재 동전을 넣었을 경우 (현재 동전 개수 1개 추가된 상태)

    for (auto& coin : coins)
    {
        for (int i = coin; i < dp.size(); ++i)
            dp[i] = min(dp[i], dp[i - coin] + 1);

    }

    if (dp.back() == 999999)
        cout << -1;
    else
        cout << dp.back();

}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

class BAEKJOON // 앱
{
public:
    int N; // 어플리캐이션 개수
    int M; // 적어도 해제가 필요한 메모리
    vector<ii> app;     // 어플리케이션 - pair<사용중인 메모리 바이트, 비활성화 비용>
    vector<int> dp;     // i 만큼의 cost를 사용했을 때, 최대로 지울 수 있는 메모리 바이트 수를 저장하는 dp

public:
    BAEKJOON() { cout << progress() << endl; }
    void init();
    int progress();
};

void BAEKJOON::init()
{
    cin >> N;
    cin >> M;

    app.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> app[i].first;

    for (int i = 0; i < N; ++i)
        cin >> app[i].second;

    // C 최댓값 100 * N 최댓값 100
    dp.resize(10001);
}

int BAEKJOON::progress()
{
    init();

    int byte = 0;
    int cost = 0;

    // i 만큼의 cost를 사용했을 때, 해제할 수 있는 최대 byte 수를 dp에 저장.
    //  dp[i - cost] + byte => dp[i - cost]에서 앱을 비활성화 시켰을 때 해제한 바이트 수.
    //  dp[i]               => 기존 값
    //  해제한 바이트 수가 많은 것을 dp에 저장시킴.

    for (auto& it : app)
    {
        byte = it.first;
        cost = it.second;

        for (int i = 10000; i >= 0; --i)
            if (i - cost >= 0)
                dp[i] = max(dp[i], dp[i - cost] + byte);
    }

    for (int i = 0; i <= 10000; ++i)
        if (M <= dp[i])
            return i;

    return 0;
}

int main()
{
    BAEKJOON b;
    return 0;
}


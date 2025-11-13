#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

struct Component
{
    vector<int> defaultComponent;
    vector<int> middleComponent;
};

vector<Component> dp;

void DFS(int cur)
{
    auto& defaults = dp[cur].defaultComponent;
    auto& middles = dp[cur].middleComponent;

    // 기본 부품 개수가 설정된 경우 return
    if (!defaults.empty())
        return;

    // 기본 부품 설정
    defaults.resize(middles.size());

    for (int i = 1; i < defaults.size(); ++i)
    {
        // 부품이 필요 없거나 자신인 경우
        if (!middles[i] || i == cur)
            continue;

        // 기본 부품 설정
        DFS(i);

        auto& nextDefaults = dp[i].defaultComponent;

        for (int j = 1; j < nextDefaults.size(); ++j)
            defaults[j] += nextDefaults[j] * middles[i];
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);


    // 장난감 조립해야 해요

    // DP 문제 같아요. 미친 중복 연산이 일어날 가능성이 높아보여요.
    // 문제에서 사이클이 발생할 여지가 없다고 했으니 DP를 사용해보는 게 좋을 것 같아요.

    // DP의 각 요소는 부품의 수를 저장하는 것이 좋아보여요.
    // 기본 부품 수 배열과  (기본 부품 수 + 중간 부품 수) 배열을 멤버로 두고

    // 만약 기본 부품 배열이 설정되지 않았으면
        // (기본 부품 수 + 중간 부품 수) 배열이 비어있다면 현재 부품은 기본 부품.
        // (기본 부품 수 + 중간 부품 수) 배열이 비어있지 않다면 현재 부품은 DP가 초기화되지 않음.
            // 이 경우에는 기본 부품으로 변환해야 해요.

    int N, M;
    cin >> N >> M;

    dp.resize(N + 1);

    while (M--)
    {
        int X, Y, K;
        cin >> X >> Y >> K;

        auto& middles = dp[X].middleComponent;
        if (middles.empty())
            middles.resize(N + 1);

        middles[Y] = K;
    }

    for (int i = 1; i < N + 1; ++i)
    {
        auto& defaults = dp[i].defaultComponent;
        auto& middles = dp[i].middleComponent;

        if (!middles.empty())
            continue;

        defaults.resize(N + 1);
        defaults[i] = 1;
    }

    DFS(N);

    for (int i = 1; i < N + 1; ++i)
    {
        if (dp.back().defaultComponent[i] == 0)
            continue;

        cout << i << ' ' << dp.back().defaultComponent[i] << endl;
    }

    return 0;
}

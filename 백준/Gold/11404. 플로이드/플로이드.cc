///////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cmath>

using namespace std;

#define endl ("\n")

class Boj
{
private:
    int N, M; // 도시의 개수, 버스의 개수

    vector<vector<int>> dp;

public:

    void input()
    {
        cin >> N >> M;

        dp.resize(N + 1, vector<int>(N + 1, 1e9));

        int s, e, w;
        while (M--)
        {
            cin >> s >> e >> w;
            dp[s][e] = min(dp[s][e], w);
        }

        for (int i = 1; i <= N; ++i)
            dp[i][i] = 0;
    }

    void progress()
    {
        for (int n = 1; n <= N; ++n) // 중간에 거쳐갈 노드
        for (int i = 1; i <= N; ++i) // 시작 노드
        for (int j = 1; j <= N; ++j) // 도착 노드
            dp[i][j] = min(dp[i][j], dp[i][n] + dp[n][j]);

        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
                cout << (dp[i][j] == 1e9 ? 0 : dp[i][j]) << " ";

            cout << endl;
        }
    }

private:


};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}


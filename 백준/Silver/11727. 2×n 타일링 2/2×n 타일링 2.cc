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
    int N;
    vector<int> dp;

public:

    void input()
    {
        cin >> N;
        dp.resize(N + 1);
    }

    void progress()
    {
        dp[1] = 1;
        if (N == 1)
        {
            cout << dp[1] << endl;
            return;
        }

        dp[2] = 3; // =, ||, ㅁ
        if (N == 2)
        {
            cout << dp[2] << endl;
            return;
        }

        dp[3] = dp[2] + dp[1] * 2;    // =|, |||, ㅁ|,   |=, |ㅁ
        if (N == 3)
        {
            cout << dp[3] << endl;
            return;
        }

        for (int i = 4; i <= N; ++i)
            dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;

        cout << dp.back();
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


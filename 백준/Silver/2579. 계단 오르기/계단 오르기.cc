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

struct node
{
    int n, c;
};

class Boj
{
private:
    int N; // 계단 수

    vector<int> stairs;
    vector<int> dp;

public:

    void input()
    {
        cin >> N;
        stairs.resize(N);
        dp.resize(N);

        for (int i = 0; i < N; ++i)
            cin >> stairs[i];
    }

    void progress()
    {
        dp[0] = stairs[0];

        if (N == 1)
        {
            cout << dp[0];
            return;
        }

        dp[1] = stairs[0] + stairs[1];
        if (N == 2)
        {
            cout << dp[1];
            return;
        }
        dp[2] = max(stairs[1] + stairs[2], stairs[0] + stairs[2]);
        if (N == 3)
        {
            cout << dp[2];
            return;
        }


        //dp[3] = 01 3, 0 23
        //dp[3] = max(dp[2] + stairs[3], stairs[1] + stairs[2]);

        for (int i = 3; i < N; ++i)
            dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);


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


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

#define endl "\n"

struct fib
{
    int zero, one;

    fib operator + (fib& other)
    {
        return { zero + other.zero, one + other.one };
    }
};

class Boj
{
private:
    int T; // 테케 개수
    vector<fib> dp;

public:

    void input()
    {
        cin >> T;
        dp.resize(41);
        dp[0] = { 1, 0 };
        dp[1] = { 0, 1 };
        dp[2] = { 1, 1 };
    }

    void progress()
    {
        for (int i = 3; i < 41; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        int in;
        while (T--)
        {
            cin >> in;
            cout << dp[in].zero << " " << dp[in].one << endl;
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


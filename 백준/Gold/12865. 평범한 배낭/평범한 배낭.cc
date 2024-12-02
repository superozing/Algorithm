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

struct item
{
    int w, p;
};

class Boj
{
private:
    int N, K; // 물품의 수, 준서가 버틸 수 있는 무게

    vector<item> items;
    vector<int> dp;

public:

    void input()
    {
        cin >> N >> K;
        items.resize(N);
        dp.resize(K + 1);

        for (int i = 0; i < items.size(); ++i)
            cin >> items[i].w >> items[i].p;
    }

    void progress()
    {
        for (item& it : items)
        {
            auto prevdp = dp;

            for (int i = it.w; i <= K; ++i)
                dp[i] = max(prevdp[i], prevdp[i - it.w] + it.p);
        }

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


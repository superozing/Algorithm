////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

constexpr auto INF = 9999;

class Boj
{
private:
    int T; // 테케 개수
    vector<int> N; // 정수

public:
    void input()
    {
        cin >> T;
        N.resize(T);
        for (int i = 0; i < T; ++i)
            cin >> N[i];
    }

    void progress()
    {
        vector<int> dp(11);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i < dp.size(); ++i)
            dp[i] += dp[i - 1] + dp[i - 2] + dp[i - 3];
    
        for (int i = 0; i < T; ++i)
            cout << dp[N[i]] << endl;
    }

};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}

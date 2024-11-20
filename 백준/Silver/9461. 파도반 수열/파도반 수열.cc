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
    int T;
    vector<long long> dp;

public:

    void input()
    {
        // i = i-1 + (i-1 - i-2) + 1?
        cin >> T;
    
        dp.resize(101);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        dp[6] = 3;
    }

    void progress()
    {
       for (int i = 7; i <= 100; ++i)
           dp[i] = dp[i - 1] + dp[i - 5];

       // 1 1 1 2 2 3 4 5 7 9 12 ?
      
       int in;
       while (T--)
       {
           cin >> in;
           cout << dp[in] << endl;
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


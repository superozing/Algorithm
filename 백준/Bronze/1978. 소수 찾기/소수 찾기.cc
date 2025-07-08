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
#include <cmath>

using namespace std;

class Boj
{
private:
    int N;
    vector<bool> dp;

public:

    void input()
    {
        cin >> N;
    
        dp.resize(1001, true);
    }

    void progress()
    {
        temp();

        int answer = 0;

        int in;
        while (N--)
        {
            cin >> in;

            if (dp[in])
                ++answer;
        }


        printf("%d", answer);
    }

private:

    void temp()
    {
        dp[1] = false;

        for (int i = 2; i < sqrt(1000); ++i)
        {
            if (dp[i])
            {
                for (int j = i + i; j <= 1000; j += i)
                    dp[j] = false;
            }
        }
    }

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


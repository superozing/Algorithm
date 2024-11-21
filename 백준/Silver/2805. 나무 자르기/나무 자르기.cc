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
    int N; // 나무의 수
    int M; // 적어도 M미터의 나무

    int maxHeight;

    vector<int> logs;

public:

    void input()
    {
        cin >> N >> M;
        
        logs.resize(N);

        maxHeight = 0;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> logs[i];
            maxHeight = max(maxHeight, logs[i]);
        }
    }

    void progress()
    {
        int l = 0;
        int r = maxHeight;

        while (l <= r)
        {
            int m = (l + r) / 2;

            long long cut = cutting(m);

            if (M == cut)
            {
                cout << m;
                return;
            }
            else if (M > cut)
                r = m - 1;
            else
                l = m + 1;
        }

        cout << r;
        return;
    }

private:

    long long cutting(int m)
    {
        long long treeSize = 0;

        for (int log : logs)
            treeSize += log - m < 0 ? 0 : log - m;

        return treeSize;
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


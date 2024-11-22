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
    vector<int> in;
    vector<int> sorted;
    unordered_map<int, int> um;

public:

    void input()
    {
        cin >> N;
        in.resize(N);
        sorted.resize(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> in[i];
            sorted[i] = in[i];
        }

        sort(sorted.begin(), sorted.end());

        int i = 0;
        int prev = 1e9 + 1;

        for (int it : sorted)
        {
            if (it == prev)
                continue;

            um.insert({ it, i });
            prev = it;
            ++i;
        }

    }

    void progress()
    {
        for (int it : in)
            cout << um[it] << " ";
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


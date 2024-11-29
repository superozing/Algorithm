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

struct num
{
    long long n;
    int c;
};

class Boj
{
private:
    int A, B; // 시작 지점, 도착 지점

public:

    void input()
    {
        cin >> A >> B;
    }

    void progress()
    {
        queue<num> q;

        q.push({ A, 1 });

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            cur.c++;

            auto next = cur;
            next.n *= 2;
            if (next.n > 1e9)
                continue;
            if (next.n == B)
            {
                cout << next.c;
                return;
            }
            q.push(next);

            next = cur;
            next.n *= 10;
            next.n++;
            if (next.n > 1e9)
                continue;
            if (next.n == B)
            {
                cout << next.c;
                return;
            }
            q.push(next);
        }

        cout << -1;
        return;
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


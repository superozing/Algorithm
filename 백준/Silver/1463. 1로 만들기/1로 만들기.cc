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
    int N;

public:

    void input()
    {
        cin >> N;
    }

    void progress()
    {
        queue<node> q;

        q.push({ N, 0 });

        while (!q.empty())
        {
            node cur = q.front();
            q.pop();

            if (cur.n == 1)
            {
                cout << cur.c;
                break;
            }

            if (cur.n % 3 == 0)
                q.push({ cur.n / 3, cur.c + 1 });
            if (cur.n % 2 == 0)
                q.push({ cur.n / 2, cur.c + 1 });
            
            q.push({ cur.n - 1, cur.c + 1 });
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


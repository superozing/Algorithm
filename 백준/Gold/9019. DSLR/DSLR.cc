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

struct d
{
    int n;
    string s;
};

int start;
int dest;

struct cmp
{
    bool operator()(d& a, d& b)
    {
        return abs(a.n - dest) > abs(b.n - dest);
    }
};

class Boj
{
private:
    int T; // 테스트케이스 개수

public:

    void input()
    {
        cin >> T;
    }

    void progress()
    {
        while (T--)
        {
            cin >> start >> dest;
            bfs();
        }
    }

private:

    void bfs()
    {
        vector<bool> visited(10000);
        queue<d> q;
        d next;
        int digitCnt;
        q.push({ start, "" });

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            next = cur;
            next.s += 'D';
            next.n = (next.n * 2) % 10000;

            if (!visited[next.n])
            {
                visited[next.n] = true;
                q.push(next);
            }
            if (next.n == dest)
            {
                cout << next.s << endl;
                break;
            }

            next = cur;
            next.s += 'S';

            if (next.n == 0)
                next.n = 9999;
            else
                next.n--;

            if (!visited[next.n])
            {
                visited[next.n] = true;
                q.push(next);
            }
            if (next.n == dest)
            {
                cout << next.s << endl;
                break;
            }

            next = cur;
            next.s += 'L';
            next.n = (next.n % 1000) * 10 + (next.n / 1000);
            if (!visited[next.n])
            {
                visited[next.n] = true;
                q.push(next);
            }
            if (next.n == dest)
            {
                cout << next.s << endl;
                break;
            }

            next = cur;
            next.s += 'R';
            next.n = (next.n / 10) + (next.n % 10) * 1000;
            if (!visited[next.n])
            {
                visited[next.n] = true;
                q.push(next);
            }
            if (next.n == dest)
            {
                cout << next.s << endl;
                break;
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


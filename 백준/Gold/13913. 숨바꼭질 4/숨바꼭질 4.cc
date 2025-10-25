#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

constexpr int MAX = 200000;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> parent(MAX, -1);

    queue<int> q;
    q.push(N);
    parent[N] = -999;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int next = cur;
        next++;
        if (next < MAX && parent[next] == -1)
        {
            parent[next] = cur;
            q.push(next);

            if (next == K)
                break;
        }

        next = cur;
        next--;
        if (next >= 0 && parent[next] == -1)
        {
            parent[next] = cur;
            q.push(next);

            if (next == K)
                break;
        }

        next = cur;
        next *= 2;
        if (next < MAX && parent[next] == -1)
        {
            parent[next] = cur;
            q.push(next);

            if (next == K)
                break;
        }
    }

    vector<int> v;
    int cur = K;
    while (cur != -999)
    {
        v.push_back(cur);
        cur = parent[cur];
    }

    cout << v.size() - 1 << endl;

    for (int i = 0; i < v.size(); ++i)
        cout << v[v.size() - 1 - i] << ' ';

    return 0;
}

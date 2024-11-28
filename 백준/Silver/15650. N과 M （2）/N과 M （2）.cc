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
    int N, M;
    vector<bool> visited;

public:

    void input()
    {
        cin >> N >> M;
        visited.resize(N + 1);
    }

    void progress()
    {
        for (int i = 1; i <= N; ++i)
        {
            visited[i] = true;
            bfs(i, 1);
            visited[i] = false;
        }
    }

private:

    void bfs(int cur, int cnt)
    {
        if (cnt == M)
        {
            for (int i = 1; i < visited.size(); ++i)
            {
                if (visited[i])
                    cout << i << " ";
            }
            cout << endl;

            return;
        }

        for (int i = cur; i <= N; ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                bfs(i, cnt + 1);
                visited[i] = false;
            }
        }

        return;
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


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
    int N, M; // 1~N까지 자연수 중 M개를 고른 수열
    vector<int> visited;

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
            visited[i] = 1;
            dfs(i, 1);
            visited[i] = 0;
        }
    }

private:

    void dfs(int cur, int cnt)
    {
        if (cnt == M)
        {
            for (int i = 0; i <= N; ++i)
            {
                for (int j = 0; j < visited[i]; ++j)
                    cout << i << " ";
            }
            cout << endl;
            return;
        }

        // 자기 자신도 포함한대요.
        visited[cur]++;
        dfs(cur, cnt + 1);
        visited[cur]--;

        for (int i = cur + 1; i <= N; ++i)
        {
            if (visited[i] == 0)
            {
                visited[i]++;
                dfs(i, cnt + 1);
                visited[i]--;
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


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
    int N; // 지역 개수
    int M; // 수색 범위
    int R; // 길의 개수

    vector<vector<int>> dist;

    vector<int> node;

public:

    void input()
    {
        cin >> N >> M >> R;
        node.resize(N + 1);
        dist.resize(N + 1, vector<int>(N + 1, 1e9));

        for (int i = 1; i < node.size(); ++i)
            cin >> node[i];

        for (int i = 0; i < R; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;

            dist[a][b] = c;
            dist[b][a] = c;
        }

        for (int i = 0; i < dist.size(); ++i)
            dist[i][i] = 0;
    }

    void progress()
    {
        int answer = 0;

        for (int n = 1; n <= N; ++n)
        for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            dist[i][j] = min(dist[i][j], dist[i][n] + dist[n][j]);
    
        for (int i = 1; i <= N; ++i)
        {
            int acc = 0;
            for (int j = 1; j <= N; ++j)
            {
                if (dist[i][j] <= M)
                    acc += node[j];
            }
            answer = max(answer, acc);
        }

        cout << answer;
    }

private:

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Boj boj{};
    boj.input();
    boj.progress();

    return 0;
}


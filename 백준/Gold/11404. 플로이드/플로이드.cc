
///////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

constexpr int INF = 1e9;

class Boj
{
private:
    int N; // 도시 개수
    int M; // 버스 개수

    vector<vector<int>> graph; // inf로 초기화 하고 가중치를 담으면 되겠네요.


public:
    void input()
    {
        cin >> N >> M;
        graph.resize(N + 1, vector<int>(N + 1, INF));

        int s, e, w;
        for (int i = 0; i < M; ++i)
        {
            cin >> s >> e >> w;
            graph[s][e] = min(w, graph[s][e]);
        }

        for (int i = 1; i <= N; ++i)
            graph[i][i] = 0;
    }

    void progress()
    {
        // n: 거쳐갈 노드
        // i: 시작 노드
        // j: 도착 노드
        for (int n = 1; n <= N; ++n)
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    graph[i][j] = min(graph[i][j], graph[i][n] + graph[n][j]);

        // 출력
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
                printf("%d ", graph[i][j] >= INF ? 0 : graph[i][j]);

            printf("\n");
        }
    }

private:
    
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}



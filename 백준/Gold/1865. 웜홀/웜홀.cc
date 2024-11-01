
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

struct edge { int s, e, t; };

class Boj
{
private:
    int TC;
    int N, M, W; // 지점 수, 도로 수, 웜홀 수

    vector<edge> graph;
    vector<int> dist;
public:
    void input()
    {
        graph.clear();
        cin >> N >> M >> W;

        int s, e, t;
        while (M--)
        {
            cin >> s >> e >> t;
            graph.push_back({ s, e, t });
            graph.push_back({ e, s, t });
        }
        while (W--)
        {
            cin >> s >> e >> t;
            graph.push_back({ s, e, -t });
        }
    }

    void progress()
    {
        cin >> TC;
        while (TC--)
        {
            input();
            dist.clear();
            dist.resize(N + 1, 1e9);
            bool isMinusRepet = false;
            for (int startPoint = 1; startPoint <= N; ++startPoint)
            {
                if (dist[startPoint] != 1e9)
                    continue;

                dist[startPoint] = 0;
                // 시간이 되돌아가 있는 경우: 음수 간선이 존재하는가?를 말하는거겠죠?

                for (int i = 1; i < dist.size() - 1; ++i)
                {
                    for (int j = 0; j < graph.size(); ++j)
                    {
                        int s = graph[j].s;
                        int e = graph[j].e;
                        int t = graph[j].t;

                        dist[e] = min(dist[e], dist[s] + t);
                    }
                }

                for (int j = 0; j < graph.size(); ++j)
                {
                    int s = graph[j].s;
                    int e = graph[j].e;
                    int t = graph[j].t;

                    if (dist[e] > dist[s] + t)
                    {
                        isMinusRepet = true;
                        break;
                    }
                }

                if (isMinusRepet)
                    break;
            }
            
            if (isMinusRepet)
                printf("YES\n");
            else
                printf("NO\n");
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

    //boj.input();
    boj.progress();

    return 0;
}



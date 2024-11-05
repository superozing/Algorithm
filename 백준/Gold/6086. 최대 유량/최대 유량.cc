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
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

constexpr auto INF = 100000000;
constexpr auto MAX = 100;

class Boj
{
private:
    int N;
    int start = 'A';
    int end = 'Z';

    vector<vector<int>> pipe; // 파이프

    vector<vector<int>> cap; // 용량
    vector<vector<int>> flow; // 현재 유량

    vector<int> visited; // 정점 방문 여부

public:
    void input()
    {
        cin >> N;

        pipe.resize('z' + 1);
        cap.resize('z' + 1, vector<int>('z' + 1));
        flow.resize('z' + 1, vector<int>('z' + 1));

        char a, b;
        int c;
        while (N--)
        {
            cin >> a >> b >> c;
            pipe[a].push_back(b);
            pipe[b].push_back(a);
            cap[a][b] += c;
            cap[b][a] += c;
        }
    }

    void progress()
    {
        int answer = 0;

        while (true)
        {
            // visited 배열 초기화
            visited.clear();
            visited.resize('z' + 1, -1);

            queue<int> q;
            q.push(start);

            // 경로 탐색
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (auto dest : pipe[cur])
                {
                    if (cap[cur][dest] - flow[cur][dest] > 0 // 흐를 공간이 남아있나요?
                        && visited[dest] == -1) // 이전에 방문하지 않았나요?
                    {
                        q.push(dest);
                        visited[dest] = cur;

                        // Z에 도착? => 경로 탐색 완료
                        if (dest == end)
                            break;
                    }
                }
            }

            // 더이상 목적지까지 흐를 흐름이 없나요?
            if (visited[end] == -1)
                break;

            int iFlow = INF;
            for (int i = end; i != start; i = visited[i])
            {
                iFlow = min(iFlow, cap[visited[i]][i] - flow[visited[i]][i]);
            }


            for (int i = end; i != start; i = visited[i])
            {
                flow[visited[i]][i] += iFlow;
                flow[i][visited[i]] -= iFlow;
            }

            answer += iFlow;
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

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}



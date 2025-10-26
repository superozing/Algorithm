#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

struct Pos
{
    int y, x;
};

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    // 맥주는 초기 20개, 최대 20개까지 들고 있을 수 있다
    // 50미터에 한 병씩(ㄷㄷ) 마시려고 한다
    // 편의점에서 다시 맥주를 20개까지 채울 수 있다
    // 페스티벌에 갈 수 있다면 yes, 없다면 no

    // 상근 -> s, 페스티벌 -> d일 때
    // if (dist(s.x, d.x) + dist(s.y, d.y) < 현재 맥주의 개수 * 50) 라면
    // yes 출력
    // else
    // 편의점을 다녀가는 경로를 탐색해야 해요.

    // 여기서 현재 맥주의 개수는 항상 20개이니 항상 1000미터를 이동할 수 있고
    // 목적지까지의 모든 이동이 1000미터 이하라면 happy를 출력할 수 있어요.

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        // 0: 상근이네 집
        // 1 ~ N: 편의점
        // N + 1: 페스티벌
        vector<vector<int>> dist(N + 2, vector<int>(N + 2));
        vector<Pos> vPos(N + 2);
        vector<bool> visited(N + 2);

        for (auto& pos : vPos)
            cin >> pos.y >> pos.x;

        for (int i = 0; i < N + 2; ++i)
        for (int j = i; j < N + 2; ++j)
        {
            int curDist = abs(vPos[i].y - vPos[j].y) + abs(vPos[i].x - vPos[j].x);
            dist[i][j] = curDist;
            dist[j][i] = curDist;
        }

        visited[0] = true;
        queue<int> q;
        q.push(0);

        bool isSearchEnd = false;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int next = 0; next < N + 2; ++next)
            {
                if (visited[next] || dist[cur][next] > 1000)
                    continue;

                if (next == N + 1)
                {
                    isSearchEnd = true;
                    break;
                }

                visited[next] = true;
                q.push(next);
            }

            if (isSearchEnd)
                break;
        }

        cout << (isSearchEnd ? "happy\n" : "sad\n");
    }

    return 0;
}

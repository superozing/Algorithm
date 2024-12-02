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

struct pos
{
    int x, y;
};

class Boj
{
private:
    int N; // NxN 도시
    int M; // 남아있어야 하는 치킨집 수

    vector<pos> house; // 그냥 집
    vector<pos> chicken; // 치킨집

    vector<vector<int>> dist; // 치킨집과 집의 거리를 저장해요.

    vector<bool> visited;


    int minChickenDist = 1e9;

public:

    void input()
    {
        cin >> N >> M;
        

        int in;
        for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            cin >> in;

            switch (in)
            {
            case 1:
                house.push_back({ i, j });
                break;

            case 2:
                chicken.push_back({ i, j });
                break;
            }
        }

        dist.resize(chicken.size(), vector<int>(house.size()));
        visited.resize(chicken.size());
    }

    void progress()
    {
        // 각 치킨집 마다 모든 집까지의 치킨 거리를 저장해놓고
        // 나중에 걸러내면 될 것 같아요.

        // 예를 들어서 치킨집이 3개고 M이 2라면

        // 치킨집 1과 치킨집 2의 dp에는 각각의 치킨 거리가 저장되어있을 것이고
        // 치킨집 1과 치킨집 2의 각 집마다 치킨 거리 중 min()을 도시의 치킨 거리의 최솟값으로 보고
        // 이렇게 순열을 찾아서 가져오면 될 것 같아요.

        for (int i = 0; i < dist.size(); ++i)
        for (int j = 0; j < dist[0].size(); ++j)
            dist[i][j] = chickenDistance(i, j);

        for (int i = 0; i < chicken.size(); ++i)
        {
            visited[i] = true;
            dfs(i, 1);
            visited[i] = false;
        }

        cout << minChickenDist;
    }

private:

    int chickenDistance(int chickenIdx, int houseIdx)
    {
        return abs(chicken[chickenIdx].x - house[houseIdx].x) + abs(chicken[chickenIdx].y - house[houseIdx].y);
    }

    void dfs(int cur, int cnt)
    {
        if (cnt == M)
        {
            // 여러 개의 집에서 치킨집으로부터의 거리 중 최소 거리를 전부 더한 값
            int curChickenDist = 0;

            // 모든 집을 순회하며 최소 거리를 더하기.
            for (int j = 0; j < house.size(); ++j)
            {
                int minDist = 1e9;
                for (int i = 0; i < visited.size(); ++i)
                {
                    if (visited[i] == true)
                        minDist = min(dist[i][j], minDist);
                }

                curChickenDist += minDist;
            }

            minChickenDist = min(minChickenDist, curChickenDist);
            return;
        }


        for (int i = cur + 1; i < chicken.size(); ++i)
        {
            visited[i] = true;
            dfs(i, cnt + 1);
            visited[i] = false;
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


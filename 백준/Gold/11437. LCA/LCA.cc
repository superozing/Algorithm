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

class Boj
{
private:
    int N, M; // 노드의 개수, 테케 개수
    vector<vector<int>> edge; // 간선들

    vector<int> parent;
    vector<int> lv;



public:
    void input()
    {
        cin >> N;
        edge.resize(N + 1);
        parent.resize(N + 1);
        lv.resize(N + 1);
        
        int a, b;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }


        //for (int i = 0; i < edge.size(); ++i)
        //{
        //    cout << i << ": ";
        //    for (int j = 0; j < edge[i].size(); ++j)
        //        cout << edge[i][j] << " ";
        //    cout << endl;
        //}
    }

    void progress()
    {
        setParent(1, 0);

        cin >> M;
        
        int a, b;
        for (int i = 0; i < M; ++i)
        {
            cin >> a >> b;
            search(a, b);
        }

    }

private:
    void setParent(int cur, int par)
    {
        parent[cur] = par;
        lv[cur] = lv[par] + 1; // 자식 노드는 부모 노드보다 한 깊이 아래 있음.

        for (int i = 0; i < edge[cur].size(); ++i)
        {
            // 자신과 연결된 노드가 자신의 부모노드와 같을 경우에는 continue
            if (edge[cur][i] == par)
                continue;

            setParent(edge[cur][i], cur);
        }
    }

    void search(int a, int b)
    {
        // 1. 두 노드의 레벨을 동일하게 맞춰준다. 한 개의 낮은 노드를 높은 노드의 깊이에 맞춰주기
        if (lv[a] < lv[b])
            swap(a, b);

        while (lv[a] != lv[b])
            a = parent[a];

        // 2. 위로 올라가며 parent[a]와 parent[b]가 같을 떄 까지 반복하기
        while (a != b)
        {
            a = parent[a];
            b = parent[b];
        }

        printf("%d\n", a);
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



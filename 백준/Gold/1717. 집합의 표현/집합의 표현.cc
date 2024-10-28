///////////////////////////////////
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

class Boj
{
private:
    int N, M; // N + 1개의 집합, 입력으로 주어지는 연산의 개수
    vector<int> vtx;

public:
    void input()
    {
        cin >> N >> M;

        vtx.resize(N + 1);

        for (int i = 0; i < vtx.size(); ++i)
            vtx[i] = i;
    }

    void progress()
    {
        int input;
        int a, b;
        for (int i = 0; i < M; ++i)
        {
            cin >> input >> a >> b;

            switch (input)
            {
            case 0:
                Union(a, b);
                break;
            case 1:
                printf("%s\n", (Find(a) == Find(b) ? "YES" : "NO"));
                break;
            }
        }
    }

private:
    // 합집합
    void Union(int a, int b)
    {
        // 각 원소가 속한 집합의 루트를 찾는다.
        a = Find(a);
        b = Find(b);

        vtx[max(a, b)] = min(a, b);
    }

    // 부모 노드 탐색
    int Find(int a)
    {
        // 부모 노드(vtx[a]가 a와 같을 때)를 반환
        if (vtx[a] != a)
            return vtx[a] = Find(vtx[a]);
        return a;
    }

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


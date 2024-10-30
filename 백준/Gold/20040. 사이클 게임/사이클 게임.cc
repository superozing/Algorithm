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
    int N, M; // 점의 개수, 진행된 차례의 수

    vector<int> vtx; // 인덱스: 점의 고유 번호, value: 점이 연결된 곳

public:
    void input()
    {
        cin >> N >> M;
        
        vtx.resize(N);

        for (int i = 0; i < N; ++i)
            vtx[i] = i;
    }

    void progress()
    {
        int a, b;
        for (int testcase = 1; testcase <= M; ++testcase)
        {
            cin >> a >> b;

            if (Union(a, b))
            {
                cout << testcase;
                return;
            }
        }

        cout << 0;
        return;
    }

private:

    // 사이클 여부 반환
    bool Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (vtx[a] == b || vtx[b] == a)
            return true;

        vtx[a] = b;

        return false;
    }

    int Find(int a)
    {
        if (a != vtx[a])
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


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

struct Val
{
    int min, max;
};

class Boj
{
private:
    int N, M;
    vector<int> a;
    vector<Val> tree;

public:
    void input()
    {
        cin >> N >> M;
        int h = ceil(log2(N));
        a.resize(N);
        tree.resize((1 << h + 1));

        for (int i = 0; i < a.size(); ++i)
            cin >> a[i];
    }

    void progress()
    {
        // 세그먼트 트리에 저장하는 값이 달라져야 할까?
        // 사실 이제 트리에 저장하는 값이 두 개가 되어야 하는 것 같아요.
        // 최대랑 최소.. 그죠?
        // 이러면 루트에는 모든 노드 중 최대와 최소가 저장되어 있을 것.
        // 확인해볼까요?
        init(1, 0, N - 1);


        // M 번 만큼, a부터 b 까지의 값 중 최대, 최소를 출력
        int a, b;
        for (int i = 0; i < M; ++i)
        {
            cin >> a >> b;
            auto val = find(1, 0, N - 1, --a, --b);
            printf("%d %d\n", val.min, val.max);
        }
        
    }

private:

    void init(int node, int s, int e)
    {
        // 리프 노드까지 이동해서 값을 기록하기.
        if (s == e)
        {
            // 최소, 최대 모두 a[s]로 기록해요.
            tree[node] = { a[s], a[s] };
            return;
        }

        // 리프 노드가 아닐 경우 다음 노드로 내려가요.
        init(node * 2, s, (s + e) / 2);
        init(node * 2 + 1, (s + e) / 2 + 1, e);

        /////음...음...
        tree[node].max = max(tree[node * 2].max, tree[node * 2 + 1].max);
        tree[node].min = min(tree[node * 2].min, tree[node * 2 + 1].min);
    }

    void update(int node, int idx, int s, int e, int val)
    {
        if (idx < s || idx > e)
            return;

        // 리프 노드를 찾을 경우 리프 노드부터 순차적으로 업데이트
        if (s == e)
        {
            a[idx] = val;
            tree[node] = { val, val };
            return;
        }

        // 리프 노드로 탐색
        update(node * 2,        idx, s,                 (s + e) / 2, val);
        update(node * 2 + 1,    idx, (s + e) / 2 + 1,   e,           val);

        tree[node].min = min(tree[node * 2].min, tree[node * 2 + 1].min);
        tree[node].max = max(tree[node * 2].max, tree[node * 2 + 1].max);
    }

    Val find(int node, int s, int e, int l, int r)
    {
        // 탐색 범위 초과시 0 반환. 근데 이제 min이 있으니 min에는 INF를 넣어줘야겠죠?
        if (l > e || r < s)
            return { static_cast<int>(1e9), 0 };

        if (l <= s && r >= e)
            return tree[node];

        Val leftVal = find(node * 2, s, (s + e) / 2, l, r);
        Val rightVal = find(node * 2 + 1, (s + e) / 2 + 1, e, l, r);

        return { min(leftVal.min, rightVal.min), max(leftVal.max, rightVal.max) };
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


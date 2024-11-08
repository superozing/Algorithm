
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
#include <cmath>

using namespace std;

constexpr auto INF = 1000000001;

class Boj
{
private:
    int N, M; // 정수의 개수, 정수 쌍 개수
    vector<int> nums;
    vector<int> seg;

public:

    void input()
    {
        cin >> N >> M;
        nums.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> nums[i];

        int height = ceil(log2(N));
        seg.resize((1 << height + 1));

        init(1, 0, N - 1);
    }

    void progress()
    {
        int a, b;

        while (M--)
        {
            cin >> a >> b;
            cout << search(1, 0, N - 1, a - 1, b - 1) << '\n';
        }
    }

private:

    void init(int node, int l, int r)
    {
        if (l == r)
        {
            seg[node] = nums[l];
            return;
        }

        init(node * 2, l, (l + r) / 2);
        init(node * 2 + 1, (l + r) / 2 + 1, r);

        seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
    }

    void change(int node, int l, int r, int idx, int val)
    {
        if (idx < l || idx > r)
            return;

        if (l == r)
        {
            seg[node] = val;
            return;
        }

        change(node * 2, l, (l + r) / 2, idx, val);
        change(node * 2 + 1, (l + r) / 2 + 1, r, idx, val);
    
        seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
    }

    int search(int node, int s, int e, int l, int r)
    {
        if (r < s || l > e)
            return INF;

        if (r >= e && l <= s)
            return seg[node];

        return min(
            search(node * 2, s, (s + e) / 2, l, r),
            search(node * 2 + 1, (s + e) / 2 + 1, e, l, r)
        );

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


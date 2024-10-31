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
    int N, M, K; // 수의  개수, 수 변경 횟수

    vector<long long> a; // 
    vector<long long> tree; // 

public:
    void input()
    {
        cin >> N >> M >> K;
        int h = ceil(log2(N));
        
        tree.resize((1 << (h + 1)));
        a.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> a[i];


        init(1, 0, N - 1);
    }

    void progress()
    {
        long long input, a, b;
        for (int i = 0; i < M + K; ++i)
        {
            cin >> input >> a >> b;

            switch (input)
            {
            case 1:
                update(1, 0, N - 1, a - 1, b);
                break;
            case 2:
                cout << query(1, 0, N - 1, a - 1, b - 1) << endl;
                break;
            }
        }
        
    }

private:

    void init(long long node, long long start, long long end)
    {
        // s와 e가 똑같은 경우 leaf node
        if (start == end)
        {
            tree[node] = a[start];
            return;
        }

        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(long long node, long long start, long long end, long long l, long long r)
    {
        // 범위를 벗어난 경우
        if (l > end || r < start)
            return 0;
        // 완전히 포함하는 경우
        if (l <= start && end <= r)
            return tree[node];

        return query(node * 2, start, (start + end) / 2, l, r) + query(node * 2 + 1, (start + end) / 2 + 1, end, l, r);
    }

    void update(long long node, long long start, long long end, long long idx, long long val)
    {
        if (idx < start || idx > end)
            return;

        if (start == end)
        {
            tree[node] += (val - a[idx]); // 기존 값 차이를 반영하여 업데이트
            a[idx] = val;
            return;
        }

        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, val);
        update(node * 2 + 1, mid + 1, end, idx, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
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



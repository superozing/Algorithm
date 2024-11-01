
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

constexpr int DIV = 1000000007;

class Boj
{
private:
    int N, M, K; // N: 수의 개수, M: 수 변경 횟수, K: 구간 곱 횟수

    vector<long long> tree;
    vector<long long> nums;

public:
    void input()
    {
        cin >> N >> M >> K;
        nums.resize(N);

        for (int i = 0; i < N; ++i)
            cin >> nums[i];

        int h = ceil(log2(N));
        tree.resize(pow(2, h + 1), 1);

        // 트리 초기화
        init(1, 0, N - 1);
    
        int a, b, c;

        for (int i = 0; i < M + K; ++i)
        {
            cin >> a >> b >> c;

            switch (a)
            {
            case 1:
                fix(1, 0, N - 1, b - 1, c);
                break;
            case 2:
            {
                if (b == 0 || c == 0)
                    cout << 0 << endl;
                else
                    cout << find(1, 0, N - 1, b - 1, c - 1) << endl;
            }
                break;
            }
        }
    }

    void progress()
    {
    }

private:

    void init(int node, int s, int e)
    {
        // 리프에 도달
        // 값 넣어준 후 반환
        if (s == e)
        {
            tree[node] = nums[s];
            return;
        }

        // 리프에 도달하지 못한 경우
        // 재귀로 탐색
        init(node * 2, s, (s + e) / 2);
        init(node * 2 + 1, (s + e) / 2 + 1, e);
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % DIV;
    }

    void fix(int node, int s, int e, int idx, long long val)
    {
        // dest 번째 수를 val 로 바꾸기.
        // 만약 탐색 범위를 벗어난 경우 1을 반환(곱하기니까)
        if (s > idx || e < idx)
            return;

        // 리프에 도달한 경우
        if (s == e)
        {
            // 목적지 리프에 도달한 경우
            // 원본 수정
            nums[idx] = val;
            // 리프 노드 수정
            tree[node] = val;
            return;
        }
        
        // 아닌 경우... 아닌 경우.... 아닌 경우...
        // 이 때는 재귀
        fix(node * 2, s, (s + e) / 2, idx, val);
        fix(node * 2 + 1, (s + e) / 2 + 1, e, idx, val);

        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % DIV;
        return;
    }

    long long find(int node, int s, int e, int l, int r)
    {
        // 1. 인덱스 범위를 벗어날 경우 1 반환
        if (s > r || e < l)
            return 1;
        
        // 2. 인덱스 범위 안에 l과 r이 전부 해당될 경우 현재 노드를 반환(이미 계산된)
        if (s >= l && e <= r)
            return tree[node];
        
        // 3. 이외의 경우에 재귀호출
        return (find(node * 2, s, (s + e) / 2, l, r) * find(node * 2 + 1, (s + e) / 2 + 1, e, l, r)) % DIV;
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



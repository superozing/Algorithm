
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
    int N, M, K; // 수의 개수, 변경이 일어나는 횟수, 구간의 합을 구하는 횟수

    vector<long long> nums; // 수들
    vector<long long> fenwick; // 펜윅 트리


public:
    void input()
    {
        cin >> N >> M >> K;
        
        nums.resize(N + 1);
        fenwick.resize(N + 1);
        for (int i = 1; i <= N; ++i)
            cin >> nums[i];
        
    }

    void progress()
    {
        for (int i = 1; i <= N; ++i)
            Update(i, nums[i]);

        long long a, b, c;

        int count = M + K;

        while (count--)
        {
            cin >> a >> b >> c;

            switch (a)
            {
            case 1:
                Change(b, c, nums[b]);
                nums[b] = c;
                break;

            case 2:
                printf("%lld ", Sum(c) - Sum(b - 1));
                break;
            }


        }
    }

private:

    void Update(int idx, long long value)
    {
        while (idx < fenwick.size())
        {
            fenwick[idx] += value;
            idx += (idx & -idx);
        }
    }

    void Change(int idx, long long value, long long prev)
    {
        while (idx < fenwick.size())
        {
            fenwick[idx] += value - prev;
            idx += (idx & -idx);
        }
    }

    long long Sum(int idx)
    {
        long long res = 0;

        while (idx > 0)
        {
            res += fenwick[idx];
            idx -= (idx & -idx);
        }

        return res;
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



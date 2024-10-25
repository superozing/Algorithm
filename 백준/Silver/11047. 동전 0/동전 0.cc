
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
    int N, K; // 동전 종류의 개수, 목표 원
    vector<int> coins;
public:
    void input()
    {
        cin >> N >> K;
        coins.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> coins[i];
    }

    void progress()
    {
        int r = N - 1, answer = 0;

        while (K != 0)
            coins[r] <= K ? answer += K / coins[r], K %= coins[r] : --r;

        cout << answer;
    }

private:
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}


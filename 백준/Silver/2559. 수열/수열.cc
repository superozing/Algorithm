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
    int N, K; // n: 온도를 측정한 전체 날짜 수 k: k일동안 온도 합을 구해야 해요.
    vector<int> date;

public:
    void input()
    {
        cin >> N >> K;
        date.resize(N);

        for (int i = 0; i < date.size(); ++i)
            cin >> date[i];
    }

    void progress()
    {
        int l = 0;
        int r = K;

        int acc = 0;
        int maxTemp = 0;

        for (int i = 0; i < K; ++i)
            acc += date[i];

        maxTemp = acc;

        while (r < date.size())
        {
            acc -= date[l++];
            acc += date[r++];
            maxTemp = max(acc, maxTemp);
        }

        cout << maxTemp;
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


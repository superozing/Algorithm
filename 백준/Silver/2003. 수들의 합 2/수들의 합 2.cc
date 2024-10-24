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
    int N, M;// 요소 수, dest 수
    vector<int> seq;

public:
    void input()
    {
        cin >> N >> M;
        seq.resize(N);

        for (int i = 0; i < N; ++i)
            cin >> seq[i];
    }

    void progress()
    {
        int l = 0, r = 1;
        int cur = seq[0];
        int acc = 0;
        
        while (r < seq.size())
        {
            if (M <= cur)
            {
                if (M == cur)
                    acc++;
                cur -= seq[l++];
            }
            else
            {
                cur += seq[r++];
            }
        }

        while (M <= cur)
        {
            if (M == cur)
                acc++;
            cur -= seq[l++];
        }

        cout << acc;
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


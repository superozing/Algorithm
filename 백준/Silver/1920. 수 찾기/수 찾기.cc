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
    int N;
    vector<int> v;

public:
    void input()
    {
        cin >> N;
        v.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> v[i];

        sort(v.begin(), v.end());
    }

    void progress()
    {
        int cur;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> cur;
            int l = 0;
            int r = v.size() - 1;

            while (l <= r)
            {
                int m = (l + r) / 2;

                if (v[m] == cur)
                    break;
                else if (v[m] < cur)
                    l = m + 1;
                else
                    r = m - 1;
            }
            printf("%d\n", l <= r ? 1 : 0);
        }
        
        return;
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


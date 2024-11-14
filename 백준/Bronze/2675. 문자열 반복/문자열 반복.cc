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

class Boj
{
private:
    int T, N;
    string s;

public:

    void input()
    {
        cin >> T;
    }

    void progress()
    {
        while (T--)
        {
            cin >> N >> s;

            for (auto c : s)
            for (int i = 0; i < N; ++i)
                printf("%c", c);

            printf("\n");
        }
    } 

private:

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


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
    int N;
    int maxVal = -1e9 - 1, minVal = 1e9 + 1;

public:

    void input()
    {
        cin >> N;
    }

    void progress()
    {
        int cur;
        while (N--)
        {
            cin >> cur;

            maxVal = max(maxVal, cur);
            minVal = min(minVal, cur);
        }

        printf("%d %d", minVal, maxVal);
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


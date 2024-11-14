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
    int maxVal;
    int cnt;

public:

    void input()
    {
        maxVal = 0;
    }

    void progress()
    {
        int cur;
        for (int i = 1; i <= 9; ++i)
        {
            cin >> cur;
            if (cur > maxVal)
            {
                cnt = i;
                maxVal = cur;
            }
        }

        printf("%d\n%d", maxVal, cnt);
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


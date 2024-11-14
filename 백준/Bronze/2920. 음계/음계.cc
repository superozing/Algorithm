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
    int prev;
    int cur;

public:

    void input()
    {
    }

    void progress()
    {
        cin >> cur;
        bool isAscending = false;

        if (cur == 1)
        {
            isAscending = true;
        }
        else if (cur != 8)
        {
            printf("mixed");
            return;
        }

        for (int i = 0; i < 7; ++i)
        {
            prev = cur;
            cin >> cur;

            if ((prev < cur && !isAscending) || (prev > cur && isAscending))
            {
                printf("mixed");
                return;
            }
        }

        printf(isAscending ? "ascending" : "descending");
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


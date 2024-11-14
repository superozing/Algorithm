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
        cin >> prev >> cur;

        bool isAscending = false;

        if (prev < cur)
            isAscending = true;

        prev = cur;

        for (int i = 0; i < 6; ++i)
        {
            cin >> cur;

            if (prev < cur)
            {
                if (!isAscending)
                {
                    printf("mixed");
                    return;
                }
            }
            else if (isAscending)
            {
                printf("mixed");
                return;
            }

            prev = cur;
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


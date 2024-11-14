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
    int n;
    
public:

    void input()
    {
        cin >> n;
    }

    void progress()
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int i = 1; i <= j; ++i)
                printf("*");

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


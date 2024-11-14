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
        if (n >= 90)
            printf("A");
        else if (n >= 80)
            printf("B");
        else if (n >= 70)
            printf("C");
        else if (n >= 60)
            printf("D");
        else
            printf("F");
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


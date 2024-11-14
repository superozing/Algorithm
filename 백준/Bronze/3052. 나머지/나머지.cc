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
    unordered_set<int> us;

public:

    void input()
    {
        int in;

        for (int i = 0; i < 10; ++i)
        {
            cin >> in;
            if (us.find(in % 42) == us.end())
                us.insert(in % 42);
        }
    }

    void progress()
    {
        printf("%d", us.size());
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


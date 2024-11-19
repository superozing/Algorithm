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
#include <bitset>
#include <cmath>

using namespace std;

#define endl "\n"

class Boj
{
private:
    int N;
    int M;

    unordered_map<string, string> um;

public:

    void input()
    {
        cin >> N >> M;

        string s;
        while (N--)
        {
            cin >> s;
            cin >> um[s];
        }
    }

    void progress()
    {
        string s;
        while (M--)
        {
            cin >> s;
            cout << um[s] << endl;
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


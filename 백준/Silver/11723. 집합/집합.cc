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
    vector<bool> S;

public:

    void input()
    {
        cin >> N;
        S.resize(21);
    }

    void progress()
    {
        string str;
        int in;
        while (N--)
        {
            cin >> str;

            if (str == "add")
            {
                cin >> in;
                S[in] = true;
            }
            else if (str == "remove")
            {
                cin >> in;
                S[in] = false;
            }
            else if (str == "check")
            {
                cin >> in;
                printf("%d\n", S[in] ? 1 : 0);
            }
            else if (str == "toggle")
            {
                cin >> in;
                S[in] = !S[in];
            }
            else if (str == "all")
            {
                for (int i = 1; i <= 20; ++i)
                    S[i] = true;
            }
            else if (str == "empty")
            {
                for (int i = 0; i < 20; ++i)
                    S[i] = false;
            }
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


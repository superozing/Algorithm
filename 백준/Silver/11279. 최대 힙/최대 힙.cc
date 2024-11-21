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

#define endl ("\n")

class Boj
{
private:
    int N;

    priority_queue<int> pq;

public:

    void input()
    {
        cin >> N;
    }

    void progress()
    {
        int in;
        while (N--)
        {
            cin >> in;

            if (in == 0)
            {
                if (!pq.empty())
                {
                    cout << pq.top() << endl;
                    pq.pop();
                }
                else
                {
                    cout << 0 << endl;
                }
            }
            else
            {
                pq.push(in);
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


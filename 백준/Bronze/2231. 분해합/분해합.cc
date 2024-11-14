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

public:

    void input()
    {
        cin >> N;
    }

    void progress()
    {
        int gen;
        for (int i = 0; i < N; ++i)
        {
            gen = getGenerator(i);
            if (gen == N)
            {
                cout << i;
                return;
            }
        }
        
        cout << 0;
        return;
    }

private:

    int getGenerator(int num)
    {
        int acc = num;

        while (num != 0)
        {
            acc += num % 10;
            num /= 10;
        }

        return acc;
    }

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


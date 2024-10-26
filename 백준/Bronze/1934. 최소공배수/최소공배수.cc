///////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
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
        for (int i = 0; i < N; ++i)
        {
            int a, b;
            cin >> a >> b;

            int a2 = a, b2 = b;

            while (b2 != 0)
            {
                int r = a2 % b2;
                a2 = b2;
                b2 = r;
            }

            cout << (a * b) / a2 << endl;
        }
    }

private:
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}


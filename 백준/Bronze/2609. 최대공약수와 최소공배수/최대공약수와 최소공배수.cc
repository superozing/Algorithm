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
    int a, b;
    int GCD;

public:
    void input()
    {
        cin >> a >> b;
    }

    void progress()
    {
        GCD = gcd(a, b);
        cout << GCD << endl << (a * b) / GCD;
    }

    // 최대공약수
    int gcd(int a, int b)
    {
        int r = a;

        while (r != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }

        return a;
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


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
    int a, b, c;
    long long mul = 0;

    int nums[10] { 0, };
public:

    void input()
    {
        cin >> a >> b >> c;
    }

    void progress()
    {
        mul = (long long)a * (long long)b * (long long)c;

        int digit;
        while (mul != 0)
        {
            digit = mul % 10;
            mul /= 10;

            ++nums[digit];
        }

        for (int i = 0; i <= 9; ++i)
            printf("%d\n", nums[i]);
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


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
    int A, B;

public:

    void input()
    {
        cin >> A >> B;
    }

    void progress()
    {
        printf("%d\n", A + B);
        printf("%d\n", A - B);
        printf("%d\n", A * B);
        printf("%d\n", A / B);
        printf("%d\n", A % B);
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


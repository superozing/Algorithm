#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    string s;
    cin >> s;

    long long answer = 0;
    long long hash = 1;

    for (char c : s)
    {
        answer += (c - 'a' + 1) * hash;
        answer %= 1234567891;

        hash *= 31;
        hash %= 1234567891;
    }

    cout << answer;

    return 0;
}


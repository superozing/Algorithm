#include <iostream>
#include <algorithm>
#include <cmath>

#define endl ('\n')

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    long long N;
    cin >> N;

    N %= 7;

    // 1s 2c 3s 4s 5s 6s 7c
    if (N == 0 || N == 2)
        cout << "CY";
    else
        cout << "SK";

    return 0;
}

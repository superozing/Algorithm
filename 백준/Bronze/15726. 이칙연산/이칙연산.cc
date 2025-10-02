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

    double a, b, c;
    cin >> a >> b >> c;
    cout << max((long long)floor(a * b / c), (long long)floor(a / b * c));

    return 0;
}

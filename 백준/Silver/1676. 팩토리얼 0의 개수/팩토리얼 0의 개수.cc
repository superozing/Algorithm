#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int answer = 0;

    for (int i = 1; i <= N; ++i)
    {
        int cur = i;

        while (cur % 5 == 0)
        {
            ++answer;
            cur /= 5;
        }
    }

    cout << answer;

    return 0;
}

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

    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        cin >> N >> K;

        int answer = 0;

        while (N--)
        {
            int in;
            cin >> in;
            answer += in / K;
        }

        cout << answer << endl;
    }

    return 0;
}


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

    // 사람들은 자기보다 큰 사람이 왼쪽에 몇 명 있었는지만을 기억한다. N명의 사람이 있고, 사람들의 키는 1부터 N까지 모두 다르다.
    // 줄을 어떻게 서야 하는 지 출력

    // 우선순위 0인 애들 중 작은 것 부터 큰 것까지 출력
    // 대신 이제 출력하고 나서 그 아래에 있는 수의 우선순위를 1 줄여줘야 해요.
    int N;
    cin >> N;

    vector<int> mans(N);
    for (int i = 0; i < N; ++i)
        cin >> mans[i];

    int printCnt = 0;
    while (printCnt < N)
    {
        for (int i = 0; i < N; ++i)
        {
            if (mans[i] < 0)
                continue;

            if (mans[i] == 0)
            {
                cout << i + 1 << ' ';
                ++printCnt;

                for (int j = 0; j <= i; ++j)
                    mans[j]--;

                break;
            }
        }
    }

    return 0;
}

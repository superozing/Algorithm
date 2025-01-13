#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int answer = 0;
    
    for (int i = 666; i <= 1e9; ++i)
    {
        int sixCnt = 0;
        int cur = i;

        while (cur != 0)
        {
            if (6 == cur % 10)
                ++sixCnt;
            else
                sixCnt = 0;

            cur /= 10;

            if (sixCnt == 3)
            {
                ++answer;
                break;
            }
        }

        if (answer == N)
        {
            cout << i;
            break;
        }
    }

    return 0;
}

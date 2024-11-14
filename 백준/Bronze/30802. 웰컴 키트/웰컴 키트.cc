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
    int N;
    int arr[6]{};
    int T, P;

public:

    void input()
    {
        cin >> N;
        for (int i = 0; i < 6; ++i)
            cin >> arr[i];

        cin >> T >> P;

    }

    void progress()
    {

        // 티셔츠: 넘어가야 함
        // 펜: 넘어가면 안된다

        int tCnt = 0;
        int pCnt = 0;
        int Remaining = 0;

        for (int i = 0; i < 6; ++i)
        {
            int in = arr[i];

            tCnt += in / T;
            if (in % T != 0)
                ++tCnt;
        }

        pCnt = N / P;
        Remaining = N % P;

        cout << tCnt << "\n";
        cout << pCnt << " " << Remaining;
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


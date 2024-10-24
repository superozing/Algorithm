#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Boj
{
private:
    int N; //  수열 길이
    int S; // S를 넘어야 해요

    vector<int> sequence; // 수열

    int minLength = 100000001; // 최소 길이

public:

    void input()
    {
        cin >> N >> S;
        sequence.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> sequence[i];
    }

    void progress()
    {
        int sum = sequence[0];
        int l = 0;
        int r = 1;
        while (r < sequence.size())
        {
            // 합을 넘을 경우...
            if (sum >= S)
            {
                // 최소 길이 갱신
                minLength = min(r - l, minLength);
                sum -= sequence[l++];
            }
            else
            {
                sum += sequence[r++];
            }
        }

        while (sum >= S && (l < sequence.size()))
        {
            // 최소 길이 갱신
            minLength = min(r - l, minLength);
            sum -= sequence[l++];
        }


        cout << (minLength != 100000001 ? minLength : 0);
    }

private:
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}


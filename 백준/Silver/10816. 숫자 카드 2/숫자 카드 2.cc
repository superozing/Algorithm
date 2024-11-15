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
    int N; // 숫자 카드의 개수
    int M; // 출력할 숫자 카드 개수의 개수
    unordered_map<int, int> um;

public:

    void input()
    {
        cin >> N;

        int input;
        while (N--)
        {
            cin >> input;
            ++um[input];
        }
        
    }

    void progress()
    {
        cin >> M;

        int output;
        while (M--)
        {
            cin >> output;
            printf("%d ", um[output]);
        }
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


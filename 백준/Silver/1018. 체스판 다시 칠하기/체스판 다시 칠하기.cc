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

constexpr int INF = 1e9;

class Boj
{
private:
    int N, M;

    vector<string> board;

public:

    void input()
    {
        cin >> N >> M;
        board.resize(N);

        for (int i = 0; i < N; ++i)
            cin >> board[i];
    }
/*
10 13
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB
*/

    int bruteforce(int sX, int sY)
    {
        int wrongCnt1 = 0;
        int wrongCnt2 = 0;

        char fColor = board[sY][sX];
        char sColor = fColor == 'B' ? 'W' : 'B';

        for (int y = 0; y < 8; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                char cur = x % 2 == 0 ? fColor : sColor;

                if (board[sY + y][sX + x] != cur)
                    ++wrongCnt1;
            }

            swap(fColor, sColor);
        }

        sColor = board[sY][sX];
        fColor = sColor == 'B' ? 'W' : 'B';

        for (int y = 0; y < 8; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                char cur = x % 2 == 0 ? fColor : sColor;

                if (board[sY + y][sX + x] != cur)
                    ++wrongCnt2;
            }

            swap(fColor, sColor);
        }

        return min(wrongCnt1, wrongCnt2);
    }


    void progress()
    {
        // 슬라이딩 윈도우를 사용해야 하는가?

        // 8x8 사이즈의 슬라이딩 윈도우를 모든 경우의 수에 맞춰서 탐색해야 할 것 같아요.
        // 2 가지 경우에 수가 있다고 했다.
        // 1. 왼 쪽 위가 검은 색
        // 2. 왼 쪽 위가 하얀 색
        // 이 두가지 경우에 따라서 체스판은 반드시 동일한 모양으로만 나올 수 있고,
        // 그 중에 다른 색의 개수를 세어 반환하면 된다.


        // 1. 초기 슬라이딩 윈도우 값 할당
        // 처음에는.. 왼 쪽 위부터 하는 것이 좋아보이네요.


        /// 아.. 그냥 브루트포스 조질까?

        int answer = 1e9;

        for (int i = 0; i <= M - 8; ++i)
            for (int j = 0; j <= N - 8; ++j)
                answer = min(answer, bruteforce(i, j));


        cout << answer;

        // 근데 문제? 가 있는데, 슬라이딩 윈도우를 사용하면
        // 1번 열을 기준으로는 다음 슬라이딩 윈도우로 이동할 때 오른 쪽으로 이동해야 하고,
        // 2번 열을 기준으로는 다음 슬라이딩 윈도우로 이동할 때 왼 쪽으로 이동해야 한다.
        // 이건 홀수냐 짝수냐에 따라서 분기를 나누어주면 될 것 같아요.


        // 2. "이동"
        // 총 세 방향으로만 이동하면 되겠죠?
        // 1. 왼 쪽
        // 2. 오른 쪽
        // 3. 아래 쪽
        // 왼왼왼왼왼 아래 오오오오오 아래 이런 식으로 움직이면 되겠죠?

        // 음....

        // 오른 쪽으로 이동한다면, 첫 번째 열 (아마도 left 포인터)에서의 규칙을 기준으로 다른 점을 찾고, 마지막 열을 넣어주면 되겠죠
        // 왼쪽으로 이동한다면 마지막 열 (right 포인터 또는 l + 8)에서 다른 점을 찾고,,
        
        // 다른 점을 찾으려면 첫 번째 문자, W또는B에 따라서 결정되는데





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


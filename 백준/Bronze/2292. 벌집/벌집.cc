#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    // 테두리마다 벌집 방 개수
    // 1
    // 6
    // 12
    // 18
    // 24
    // 오 규칙을 찾았다.

    int n;
    cin >> n;

    int cur = 1;
    int lineCnt = 6;
    int answer = 1;

    while (cur < n)
    {
        cur += lineCnt;
        lineCnt += 6;
        ++answer;
    }

    cout << answer << endl;

    return 0;
}

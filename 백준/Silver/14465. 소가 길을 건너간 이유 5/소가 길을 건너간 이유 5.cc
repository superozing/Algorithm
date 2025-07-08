#include <iostream>
#include <vector>

using namespace std;

class BAEKJOON // 삼각수의 합
{
public:
    int N; // 신호등 count
    int K; // 연속으로 존재해야 하는 신호등의 개수
    int B; // 고장난 신호등의 개수
    vector<bool> road;

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:

    int search(int l, int r);

};
int BAEKJOON::search(int l, int r)
{
    static int sinhoCount = -1;

    if (-1 == sinhoCount) // 첫 실행시
    {
        sinhoCount = 0;
        for (int i = l; i <= r; ++i)
        {
            if (road[i])
                ++sinhoCount;
        }
    }
    else // 이후 실행시
    {
        if (road[l - 1] == true)
            --sinhoCount;
        if (road[r] == true)
            ++sinhoCount;
    }

    return sinhoCount;
}

void BAEKJOON::init()
{
    cin >> N;
    road.resize(N + 1);
    cin >> K;
    cin >> B;

    int buf = 0;

    for (int i = 0; i < B; ++i)
    {
        cin >> buf;
        road[buf] = true;
    }
}

void BAEKJOON::progress()
{
    // 슬라이딩 윈도우 문제.
    // 윈도우 크기: K

    // 최소 몇 개의 신호등을 수리해야 하는가? -> bool 값 중 true의 개수.
    // left ~ right 까지의 bool 값을 계속해서 훑을 때, 가장 작은 값을 출력해야 한다.
    // 근데 이렇게 풀면 왠지 타임 아웃이 날 것 같은 느낌이 드는데요...???
    // 데이터를 중복해서 검사하면 안될 느낌이 살짝 든다.
    // 일단 중복해서 검사하는 것을 허용해서 해볼까요? -> 역시나 시간 초과가 난다.

    int left = 1;
    int right = K;

    int returnVal = K;

    while (right != N + 1)
    {
        returnVal = min(search(left, right), returnVal);
        //cout << returnVal << endl << endl;
        ++left;
        ++right;
    }

    cout << returnVal;
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}

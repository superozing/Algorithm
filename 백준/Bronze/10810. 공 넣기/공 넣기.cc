#include <iostream>
#include <vector>

using namespace std;

class BAEKJOON // 공 넣기
{
public:
    int N; // 바구니 개수
    int M; // 공을 넣을 수

    vector<int> basket;

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
};

void BAEKJOON::init()
{
    cin >> N >> M;
    basket.resize(N + 1);
}

void BAEKJOON::progress()
{
    int start = 0;
    int end = 0;
    int fill = 0;

    for (int i = 0; i < M; ++i)
    {
        cin >> start >> end >> fill;

        for (; start <= end; ++start)
            basket[start] = fill;
    }

    for (int i = 1; i < basket.size(); ++i)
        cout << basket[i] << " ";
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}

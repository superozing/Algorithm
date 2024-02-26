#include <iostream>
#include <vector>

using namespace std;

class BAEKJOON // 예산
{
public:
    int N;              // 지방 개수
    int M;              // 총 예산
    vector<int> area;   // 지방마다 요청받은 예산

    int maxBudget;

public:
    BAEKJOON() { cout << progress() << endl; }
    void init();
    int progress();

private:
    int fullBudget(int budget);
};

void BAEKJOON::init()
{
    cin >> N;

    area.resize(N);

    maxBudget = 0;

    for (int i = 0; i < N; ++i)
    {
        // M 재활용 해봤어요.
        cin >> M;
        area[i] = M;
        maxBudget = max(maxBudget, M);
    }

    cin >> M;
}

int BAEKJOON::progress()
{
    init();

    int l = 0;
    int r = maxBudget;
    int sum = 0;
    int mid = 0;

    while (l <= r)
    {
        mid = (l + r) / 2;

        sum = fullBudget(mid);

        // 준비된 예산보다 작을 경우
        if (M >= sum)
            l = mid + 1;

        // 준비된 예산보다 클 경우
        else
            r = mid - 1;
    }

    return r;
}

int BAEKJOON::fullBudget(int budget)
{
    int ret = 0;

    for (int i = 0; i < area.size(); ++i)
        ret += min(area[i], budget);

    return ret;
}

int main()
{
    BAEKJOON b;

    return 0;
}


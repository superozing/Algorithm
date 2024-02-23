#include <iostream>
#include <vector>

using namespace std;

class BAEKJOON // 삼각수의 합
{
public:
    int N; // 노래 개수
    int L; // 노래 하나 당 길이
    int D; // 전화벨이 울리는 간격
    vector<bool> vec;

public:
    BAEKJOON() { cout << progress(); }
    void init();
    int progress();

};

void BAEKJOON::init()
{
    cin >> N;
    cin >> L;
    cin >> D;
}

int BAEKJOON::progress()
{
    init();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < L; ++j)
            vec.push_back(true);
        for (int j = 0; j < 5; ++j)
            vec.push_back(false);
    }

    // 중간에 쉬는 시간: 5초
    int i = 1;
    for (; i * D < vec.size(); ++i)
    {
        if (vec[i * D] == false)
            return i * D;
    }

    return i * D;

}

int main()
{
    BAEKJOON b;

    return 0;
}

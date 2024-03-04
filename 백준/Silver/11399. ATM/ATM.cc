#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class BAEKJOON // ATM
{
public:
    int N; // 사람
    vector<int> line; // 줄

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
};

void BAEKJOON::init()
{
    cin >> N;

    int buf = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> buf;
        line.push_back(buf);
    }

    sort(line.begin(), line.end());
}

void BAEKJOON::progress()
{
    // 정렬된 순서로 걸리는 시간 구하기
    for (int i = 1; i < line.size(); ++i)
        line[i] += line[i - 1];


    int buf = 0;

    // 구한 값 더하기
    for (auto& it : line)
        buf += it;

    cout << buf;
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}

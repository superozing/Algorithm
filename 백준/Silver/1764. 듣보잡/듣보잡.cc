#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

class BAEKJOON // 듣보잡
{
public:
    int N; // 듣도 못한 사람
    int M; // 보도 못한 사람

    set<string> s; // 듣도 못한 사람 명단

    set<string> v; // 듣도 보도 못한 사람 명단

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
};

void BAEKJOON::init()
{
    cin >> N >> M;

    string buf{};

    // 듣
    for (int i = 0; i < N; ++i)
    {
        cin >> buf;
        s.insert(buf);
    }
}

void BAEKJOON::progress()
{
    string buf{};

    // 보
    for (int i = 0; i < M; ++i)
    {
        cin >> buf;

        if (s.find(buf) != s.end())
            v.insert(buf);
    }

    cout << v.size() << endl;

    // 듣보
    for (auto& it : v)
        cout << it << endl;

}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}

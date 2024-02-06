#include <iostream>
#include <vector>

using namespace std;


class BAEKJOON // 삼각수의 합
{
public:
    vector<int> vIn;

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

};

void BAEKJOON::init()
{
    int a = 0;
    cin >> a;

    int buf = 0;
    for (int i = 0; i < a; ++i)
    {
        cin >> buf;
        vIn.push_back(buf);
    }

}

void BAEKJOON::progress()
{
    for (int i = 0; i < vIn.size(); ++i)
    {
        int T = 1;
        int ans = 0;

        for (int k = 1; k < vIn[i] + 1; ++k)
        {
            T += k + 1;
            ans += k * T;
        }

        cout << ans << endl;
    }
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}

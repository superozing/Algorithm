#include <iostream>
#include <string>

using namespace std;


class BAEKJOON // 컵홀더
{
public:
    string  s;
    int     n;

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

};

void BAEKJOON::init()
{
    cin >> n;
    cin >> s;
}

void BAEKJOON::progress()
{
    int returnVal = n + 1;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'L')
        {
            ++i;
            --returnVal;
        }
    }

    if (n < returnVal)
        --returnVal;

    cout << returnVal;
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}

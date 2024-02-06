#include <iostream>
#include <queue>

using namespace std;


class BAEKJOON // 최대 힙
{
public:
    priority_queue<int> pq;
     long long         count;

public:
    BAEKJOON() { progress(); }
    void progress();

};

void BAEKJOON::progress()
{
    scanf("%lld", &count);

    int    buf = 0;

    for (int i = 0; i < count; ++i)
    {
        scanf("%d", &buf);

        if (buf != 0)
        {
            pq.push(buf);
        }
        else
        {
            if (pq.empty())
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
    }
}

int main()
{
    BAEKJOON b;

    return 0;
}

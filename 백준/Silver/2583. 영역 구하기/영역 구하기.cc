#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

class BAEKJOON // 영역 구하기
{
public:
    int x;
    int y;
    int k;

    vector<string> p;
    vector<int> width;

public:
    BAEKJOON() { init(); }
    void init();
    void progress();
    void print();

    int search(int x, int y);
};

/*
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
*/
void BAEKJOON::init()
{
    cin >> y;
    cin >> x;

    string s;

    for (int i = 0; i < x; ++i)
        s += 'x';

    for (int i = 0; i < y; ++i)
        p.push_back(s);

    cin >> k;

    int left = 0;
    int top = 0;
    int right = 0;
    int bottom = 0;

    for (int i = 0; i < k; ++i)
    {
        cin >> left;
        cin >> top;
        cin >> right;
        cin >> bottom;

        for (int j = left; j < right; ++j)
            for (int k = top; k < bottom; ++k)
                p[k][j] = 'o';

    }
}

typedef pair<int, int> ii;

int BAEKJOON::search(int Y, int X)
{
    list<ii> queue;
    int count = 0;
    queue.push_back({ Y, X });
    p[Y][X] = 'o';

    while (!queue.empty())
    {
        ii b = queue.front();
        queue.pop_front();
        ++count;

        int cY = b.first;
        int cX = b.second;
        if (cX != 0 && p[cY][cX - 1] == 'x') // 왼 쪽
        {
            p[cY][cX - 1] = 'o';
            queue.push_back({ cY, cX - 1 });
        }
        if (cX + 1 < x && p[cY][cX + 1] == 'x') // 오른 쪽
        {
            p[cY][cX + 1] = 'o';
            queue.push_back({ cY, cX + 1 });
        }
        if (cY != 0 && p[cY - 1][cX] == 'x') // 위 쪽
        {
            p[cY - 1][cX] = 'o';
            queue.push_back({ cY - 1, cX });
        }
        if (cY + 1 < y && p[cY + 1][cX] == 'x') // 아래 쪽
        {
            p[cY + 1][cX] = 'o';
            queue.push_back({ cY + 1, cX });
        }
    }

    return count;
}

void BAEKJOON::progress()
{
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            if (p[i][j] == 'x')
                width.push_back(search(i, j));
        }
    }
}

void BAEKJOON::print()
{
    cout << width.size() << endl;

    sort(width.begin(), width.end());

    for (auto& it : width)
        cout << it << ' ';

    cout << endl;
}

int main()
{
    BAEKJOON b;
    b.progress();
    b.print();
    return 0;
}

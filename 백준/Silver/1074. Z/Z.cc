#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Boj
{
private:
    int N;
    int R, C; // r행, c열이 몇 번째로 방문되는지.

    // 근데 굳이 벡터가 필요한가? 라는 생각도 들어요.
    // 변수로 상상 벡터를 만들어볼까?

    int visitOrder;

public:
    void input()
    {
        visitOrder = 0;
        cin >> N;

        cin >> R >> C;
    }

    void progress()
    {
        if (!R && !C)
        {
            cout << 0;
            return;
        }
        while (N != 0)
        {
            Z();
            --N;
        }

        cout << visitOrder;
    }

    void Z()
    {
        // 인덱스에 맞는 4개 방면 중 하나를 들어가야 해요.
        // 이 때, 어느 위치로 가냐에 따라 더해주어야 할 수가 달라져요.

        // n = 3의 경우 2^3 = 8.
        //좌상: (2^3 / 2)^2 * 0;
        //우상: (2^3 / 2)^2 * 1;
        //좌하: (2^3 / 2)^2 * 2;
        //우하: (2^3 / 2)^2 * 3;

        // 내려가면 R,C에서 2^n / 2로 나눠주면 되겠어요.

        int curLine = pow(2, N);
        int curLineMul2 = pow(curLine/2, 2);

        int squareLocation = 0;

        // 1,2
        if (R < curLine / 2)
        {
            if (C < curLine / 2)
                squareLocation = 0;
            else
                squareLocation = 1;
        }
        // 3,4
        else
        {
            if (C < curLine / 2)
                squareLocation = 2;
            else
                squareLocation = 3;
        }


        visitOrder += curLineMul2 * squareLocation;

        if (R != 0)
            R %= (curLine / 2);
        if (C != 0)
            C %= (curLine / 2);
    }
    
private:
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}

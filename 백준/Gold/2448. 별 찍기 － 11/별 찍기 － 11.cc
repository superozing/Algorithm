///////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cmath>

using namespace std;

#define endl ("\n")

class Boj
{
private:
    int N; // 한 변의 길이?

    vector<string> triangle;

public:

    void input()
    {
        cin >> N;
        // 줄 수: N개?
        // 문자 수: N * 2 - 1 개?
        triangle.resize(N, string(N * 2, ' '));
    }

    void progress()
    {
        divideAndConquer(N - 1, 0, N);

        for (string& s : triangle)
            cout << s << endl;
    }

private:

    void divideAndConquer(int startY, int startX, int sideLength)
    {
        if (sideLength == 3)
        {
            // 별 그리기
            triangle[startY][startX] = '*';
            triangle[startY][startX + 1] = '*';
            triangle[startY][startX + 2] = '*';
            triangle[startY][startX + 3] = '*';
            triangle[startY][startX + 4] = '*';

            triangle[startY - 1][startX + 1] = '*';
            triangle[startY - 2][startX + 2] = '*';
            triangle[startY - 1][startX + 3] = '*';

            return;
        }
        
        // 3개의 삼각형을 재귀 호출 해야 해요.
        // 모든 입력은 왼 쪽 하단을 기준으로 생각하고 재귀호출 해볼까요?
        int div2Side = sideLength / 2;
        int div2Y = startY / 2;
        int div2X = startX / 2;

        // 첫 입력이 6이라면, y를 startY, startY, 3(startY - sideLength) 위치에 해야 해요.
        // 첫 입력이 6이라면, x를 startX, 6(startX + sideLength), 3(startX + sideLength - sideLength / 2) 위치에 해야 해요.
        // 왼 쪽 아래 삼각형
        divideAndConquer(startY, startX, div2Side);

        // 오른 쪽 아래 삼각형
        divideAndConquer(startY, startX + sideLength, div2Side);

        // 위 쪽 삼각형
        divideAndConquer(startY - div2Side, startX + div2Side, div2Side);

        return;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}


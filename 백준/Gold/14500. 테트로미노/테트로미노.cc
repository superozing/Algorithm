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

struct d
{
    int n;
    string s;
};

int start;
int dest;

struct cmp
{
    bool operator()(d& a, d& b)
    {
        return abs(a.n - dest) > abs(b.n - dest);
    }
};

class Boj
{
private:
    int N, M; // 세로, 가로

    vector<vector<int>> grid;

public:

    void input()
    {
        cin >> N >> M;
        grid.resize(N, vector<int>(M));

        for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            cin >> grid[y][x];
    }

    void progress()
    {

        // ㅗ, ㅜ, ㄴ, ㄱ. ㄱㄴ

        int answer = 0;

        for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
        {
            answer = max(answer, search(y, x));
        }

        cout << answer;
    }

private:

    int search(int y, int x)
    {
        int maxValue = 0;

        // 일자: 남은 인덱스가 4칸 이상 남아있는 경우
        if (y + 4 <= N)
            maxValue = max(grid[y][x] + grid[y + 1][x] + grid[y + 2][x] + grid[y + 3][x], maxValue);
        if (x + 4 <= M)
            maxValue = max(grid[y][x] + grid[y][x + 1] + grid[y][x + 2] + grid[y][x + 3], maxValue);

        // 사각형: y, x가 모두 2 이상 남아있는 경우
        if (y + 2 <= N && x + 2 <= M)
            maxValue = max(grid[y][x] + grid[y + 1][x] + grid[y][x + 1] + grid[y + 1][x + 1], maxValue);


        // y 2칸, x 3칸 남는 경우
        // OOO
        // OOO
        if (y + 2 <= N && x + 3 <= M)
        {
            // ㄱ 모양
            // OOO  
            //   O  
            maxValue = max(grid[y][x] + grid[y][x + 1] + grid[y][x + 2] + grid[y + 1][x + 2], maxValue);

            // OOO
            // O  
            maxValue = max(grid[y][x] + grid[y + 1][x] + grid[y][x + 1] + grid[y][x + 2], maxValue);

            // O  
            // OOO
            maxValue = max(grid[y][x] + grid[y + 1][x] + grid[y + 1][x + 1] + grid[y + 1][x + 2], maxValue);

            //   O
            // OOO
            maxValue = max(grid[y + 1][x] + grid[y + 1][x + 1] + grid[y + 1][x + 2] + grid[y][x + 2], maxValue);


            // ㄱㄴ 모양
            // OO   OO
            //  OO OO
            maxValue = max(grid[y][x] + grid[y][x + 1] + grid[y + 1][x + 1] + grid[y + 1][x + 2], maxValue);
            maxValue = max(grid[y + 1][x] + grid[y + 1][x + 1] + grid[y][x + 1] + grid[y][x + 2], maxValue);

            
            // ㅗ 모양
            // OOO  O
            //  O  OOO
            maxValue = max(grid[y][x] + grid[y][x + 1] + grid[y][x + 2] + grid[y + 1][x + 1], maxValue);
            maxValue = max(grid[y + 1][x] + grid[y + 1][x + 1] + grid[y][x + 1] + grid[y + 1][x + 2], maxValue);
        }


        // y 3칸, x 2칸 남는 경우
        if (y + 3 <= N && x + 2 <= M)
        {
            // ㄱ 모양
            // O  
            // O 
            // OO
            maxValue = max(grid[y][x] + grid[y + 1][x] + grid[y + 2][x] + grid[y + 2][x + 1], maxValue);

            // OO
            // O
            // O 
            maxValue = max(grid[y][x] + grid[y][x + 1] + grid[y + 1][x] + grid[y + 2][x], maxValue);

            //  O  
            //  O 
            // OO
            maxValue = max(grid[y][x + 1] + grid[y + 1][x + 1] + grid[y + 2][x + 1] + grid[y + 2][x], maxValue);

            // OO
            //  O
            //  O 
            maxValue = max(grid[y][x + 1] + grid[y + 1][x + 1] + grid[y + 2][x + 1] + grid[y][x], maxValue);


            // ㄱㄴ 모양
            // O
            // OO
            //  O
            maxValue = max(grid[y][x] + grid[y + 1][x] + grid[y + 1][x + 1] + grid[y + 2][x + 1], maxValue);
            maxValue = max(grid[y][x + 1] + grid[y + 1][x + 1] + grid[y + 1][x] + grid[y + 2][x], maxValue);


            // ㅗ 모양
            // O   O
            // OO OO
            // O   O
            maxValue = max(grid[y][x] + grid[y + 1][x] + grid[y + 2][x] + grid[y + 1][x + 1], maxValue);
            maxValue = max(grid[y][x + 1] + grid[y + 1][x + 1] + grid[y + 1][x] + grid[y + 2][x + 1], maxValue);
        }

        return maxValue;
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


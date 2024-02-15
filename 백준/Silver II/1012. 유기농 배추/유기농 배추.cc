#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class BAEKJOON // 유기농 배추
{
public:

    int T; // 테스트 케이스 수

    int M; // 가로 길이 x
    int N; // 세로 길이 y
    int K; // 배추 개수

    vector<string> d; // 가로 길이는 string의 길이가 되어야 하고, 세로 길이는 string의 개수가 되어야 한다.
    vector<string> visited;


    int returnVal;

public:
    BAEKJOON() { init(); }
    void init();
    void progress();
    void search(int y, int x);

};

typedef pair<int, int> ii;


void BAEKJOON::search(int y, int x)
{
    // 자...이제 모든 배추 부분에 visited 체크를 해주어야 한다.
    // [y][x] 순으로 참조해야 한다는 것을 잊지 말아요.
    list<ii> q;

    q.push_back({ y, x });
    visited[y][x] = '1';

    while (!q.empty())
    {
        ii cur = q.front(); q.pop_front();

        int y = cur.first;
        int x = cur.second;


        // 1. 인덱스 범위 체크
        // 2. 배추 있는지 확인
        // 3. visited 확인
        if ((y + 1 < N) && (d[y + 1][x] == '1') && (visited[y + 1][x] == '0'))
        {
            q.push_back({ y + 1, x });
            visited[y + 1][x] = '1';
        }

        if ((y - 1 >= 0) && (d[y - 1][x] == '1') && (visited[y - 1][x] == '0'))
        {
            q.push_back({ y - 1, x });
            visited[y - 1][x] = '1';
        }

        if ((x + 1 < M) && (d[y][x + 1] == '1') && (visited[y][x + 1] == '0'))
        {
            q.push_back({ y, x + 1 });
            visited[y][x + 1] = '1';
        }

        if ((x - 1 >= 0) && (d[y][x - 1] == '1') && (visited[y][x - 1] == '0'))
        {
            q.push_back({ y, x - 1 });
            visited[y][x - 1] = '1';
        }
    }
}


// [y][x] 로 참조해야만 한다.
void BAEKJOON::init()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        M = 0;
        N = 0;
        K = 0;
        returnVal = 0;

        cin >> M;
        cin >> N;

        d.clear();
        visited.clear();

        string s;
        s.resize(M, '0');
        d.resize(N, s);
        visited.resize(N, s);

        cin >> K;

        int x = 0;
        int y = 0;

        for (int i = 0; i < K; ++i)
        {
            cin >> x;
            cin >> y;
            d[y][x] = '1';
        }

        progress();
    }
}


void BAEKJOON::progress()
{
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            if (visited[y][x] == '0' && d[y][x] == '1')
            {
                search(y, x);
                ++returnVal;
            }

    cout << returnVal << endl;
}


int main()
{
    BAEKJOON b;

    return 0;
}

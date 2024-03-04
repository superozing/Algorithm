#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <algorithm>

using namespace std;

class BAEKJOON // 단지번호붙이기
{
public:
    int N;                  // 지도 길이 NxN
    vector<string>  vMap;   // 지도

    vector<int>     result; // 단지 정보를 저장해요.

    int _arrX[4] = { 0, -1, 0, 1 };
    int _arrY[4] = { -1, 0, 1, 0 };

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
    int search(int y, int x);
};

void BAEKJOON::init()
{
    cin >> N;

    vMap.resize(N);

    // 지도 정보 입력받아 저장하기
    for (int i = 0; i < N; ++i)
        cin >> vMap[i];

}

typedef pair<int, int> pii;

int BAEKJOON::search(int y, int x)
{
    vMap[y][x] = '0';

    list<pii> q;
    q.push_back({ y, x });

    int Y = 0;
    int X = 0;

    int houseCount = 0;

    while (!q.empty())
    {
        // 큐의 첫 데이터 가져옴
        pii ii = q.front();
        q.pop_front();

        // 지운 집의 개수 ++
        ++houseCount;

        // 이번에는 for문 사용해보았어요.
        for (int i = 0; i < 4; ++i)
        {
            Y = ii.first + _arrY[i];
            X = ii.second + _arrX[i];

            // 인덱스 범위를 벗어나지 않으면서, 지도에서 해당 위치에 집이 있을 때 집어넣기
            if ((0 <= Y && Y < N && 0 <= X && X < N) && (vMap[Y][X] == '1'))
            {
                q.push_back({ Y, X });
                vMap[Y][X] = '0'; // 이후 집어넣은 인덱스는 0으로 비우기
            }
        }
    }

    return houseCount;
}

void BAEKJOON::progress()
{
    // 모든 지도를 순회하면서, 만약 인덱스에 집이 있을 경우 탐색
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (vMap[y][x] == '1')
                result.push_back(search(y, x));
        }
    }

    sort(result.begin(), result.end());

    // 결과 출력
    cout << result.size() << endl;

    for (auto& it : result)
        cout << it << endl;
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}

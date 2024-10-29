///////////////////////////////////
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
    int N, M;
    vector<int> cities;

public:
    void input()
    {
        cin >> N >> M;

        cities.resize(N + 1);

        for (int i = 0; i < N; ++i)
            cities[i] = i;
    }

    void progress()
    {
        int isLinked;
        for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            cin >> isLinked;
            if (isLinked)
                Union(i, j);
        }

        // M개의 도시 이동을 하니까... 입력으로 들어온 모든 도시가 연결되어있는 상태여야 해요.
        // 그러려면 첫 도시를 기준으로 잡고 다른 입력으로 들어오는 모든 도시가 같은지 확인하면 돼요.
        int startCity, destCity;
        cin >> startCity;

        startCity = Find(startCity);

        for (int i = 1; i < M; ++i)
        {
            cin >> destCity;
            if (startCity != Find(destCity))
            {
                cout << "NO";
                return;
            }
        }

        cout << "YES";
    }

private:

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        // 도시를 연결해요.
        cities[max(a, b)] = min(a, b);
    }

    int Find(int a)
    {
        // 루트 도시일 경우 반환
        if (cities[a] == a)
            return a;

        // 최상위 부모 인덱스로 통일
        return cities[a] = Find(cities[a]);
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}


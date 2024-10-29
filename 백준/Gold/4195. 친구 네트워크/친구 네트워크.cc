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

struct fr
{
    string parent;
    int cnt;
};

class Boj
{
private:
    int T;

    // 인덱스: 이름, value: 루트
    unordered_map<string, fr> um;

public:
    void input()
    {
        cin >> T;
    }

    void progress()
    {
        // 기존 유니온 파인드랑 다른 점은 문자열이라는 점이 다르겠죠?
        // 이 건 umap을 사용하면 간단하게 해결할 수 있을 것 같은 느낌이 들어요

        int testCase;
        string a, b;
        for (int i = 0; i < T; ++i)
        {
            cin >> testCase;
            for (int j = 0; j < testCase; ++j)
            {
                cin >> a >> b;
                printf("%d\n", Union(a, b));
            }
            um.clear();
        }
    }

private:

    int Union(string& x, string& y)
    {
        // 첫 insert 데이터일 시 초기화
        if (um[x].cnt == 0)
        {
            um[x].cnt = 1;
            um[x].parent = x;
        }
        if (um[y].cnt == 0)
        {
            um[y].cnt = 1;
            um[y].parent = y;
        }

        auto _x = Find(x);
        auto _y = Find(y);

        // 두 데이터가 이전에 친구가 아닐 경우
        if (_x.parent != _y.parent)
        {
            // root 통일
            um[_y.parent].parent = _x.parent;

            // cnt 이전
            um[_x.parent].cnt += um[_y.parent].cnt;
        }

        // 찾은 count를 반환해요.
        return um[_x.parent].cnt;
    }

    fr Find(string& x)
    {
        // 경로 통일
        if (um[x].parent != x)
            um[x].parent = Find(um[x].parent).parent;

        return um[x];
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


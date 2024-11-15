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
#include <cmath>

using namespace std;

struct info
{
    int age, idx;
    string name;
};

class Boj
{
private:

    int N;
    vector<info> user;

public:

    bool operator() (info& a, info& b)
    {
        return a.age == b.age ? a.idx < b.idx : a.age < b.age;
    }

    void input()
    {
        cin >> N;

        user.resize(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> user[i].age >> user[i].name;
            user[i].idx = i;
        }

    }

    void progress()
    {
        sort(user.begin(), user.end(), Boj());

        for (auto& it : user)
            printf("%d %s\n", it.age, it.name.c_str());
    }

private:

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


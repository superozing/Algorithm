#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

bool compare(ii& l, ii& r)
{
    return l.first < r.first;
}

class BAEKJOON // 신입 사원
{
public:
    int t;
    vector<int> ret;

public:
    BAEKJOON() { init(); }
    void init();
    int progress();
};

void BAEKJOON::init()
{
    cin >> t;


    for (int i = 0; i < t; ++i)
    {
        int cases = 0;

        cin >> cases;

        vector<ii> v(cases);

        for (int j = 0; j < cases; ++j)
            cin >> v[j].first >> v[j].second;

        sort(v.begin(), v.end(), compare);

        int minRank = v[0].second;

        int returnValue = 1;

        for (int k = 1; k < v.size(); ++k)
        {
            if (minRank > v[k].second)
            {
                ++returnValue;
                minRank = v[k].second;
            }
        }
        ret.push_back(returnValue);
    }

    for (auto& it : ret)
        cout << it << endl;
}
    



int main()
{
    BAEKJOON b;

    return 0;
}

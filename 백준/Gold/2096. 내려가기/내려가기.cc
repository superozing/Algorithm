///////////////////////////////////////////
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
    int N; // 줄 개수
    vector<int> mindp;
    vector<int> maxdp;
    vector<int> in;

public:
    void input()
    {
        cin >> N;
        
        mindp.resize(3);
        maxdp.resize(3);
        in.resize(3);

        N--;
        cin >> in[0] >> in[1] >> in[2];
        for (int i = 0; i < 3; ++i)
        {
            mindp[i] = in[i];
            maxdp[i] = in[i];
        }
    }

    void progress()
    {
        // 이전 dp에서 다음 dp로 갈 때, 다음 데이터를 이전에 더하면 예외를 해결하기 위해서 이전에 어떤 노드의 데이터를 더했는지 저장해야 한다.. 이러기는 너무 싫은데?
        // 아... grid 저장도 하지 말라는 빡빡빡빡한 문제가 있다니
        int a, b, c;
        while (N--)
        {
            cin >> in[0] >> in[1] >> in[2];
            a = mindp[0], b = mindp[1], c = mindp[2];
            mindp[0] = in[0] + min(a, b);
            mindp[1] = in[1] + min(a, min(b, c));
            mindp[2] = in[2] + min(b, c);

            a = maxdp[0], b = maxdp[1], c = maxdp[2];
            maxdp[0] = in[0] + max(a, b);
            maxdp[1] = in[1] + max(a, max(b, c));
            maxdp[2] = in[2] + max(b, c);
        }

        int answer = 0;

        for (int i = 0; i < 3; ++i)
            answer = max(maxdp[i], answer);
        
        cout << answer << endl;

        for (int i = 0; i < 3; ++i)
            answer = min(mindp[i], answer);
        
        cout << answer << endl;
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



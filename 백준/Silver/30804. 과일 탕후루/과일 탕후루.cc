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

struct pos
{
    int y, x;
};

class Boj
{
private:
    int N;
    vector<int> tang;

public:

    void input()
    {
        cin >> N;
        tang.resize(N);

        for (int i = 0; i < N; ++i)
            cin >> tang[i];
    }

    void progress()
    {
        if (N == 1)
        {
            cout << 1 << endl;
            return;
        }
        // 5 1 1 2 1
        // F S   C

        // 5 1 1 2 1
        //   F   S C
        // 딱 이대로만 구현하면 될 것 같아요.
        // 첫 과일 가리키는 포인터, 두 번째 과일 가리키는 포인터, current 포인터
        // 삼중 포인터를 쓰는거에요.

        int answer = 0;

        int firFruit = tang[0];
        int firPtr = 0;
        int secFruit = 0;
        int secPtr = 0;

        // 두 번째 과일 시작점 찾기
        for (int i = 1; i < tang.size(); ++i)
        {
            if (tang[i] != firFruit)
            {
                secFruit = tang[i];
                secPtr = i;
                break;
            }
        }


        // 1 1 1 2 1 1 3 3 
        // F     S C      
        // 
        // 이런 경우에 어떻게 판단해야 하지?? -> 버퍼를 하나 두자
        
        // 1 1 1 2 1 1 3 3 
        // B     F S   C


        int buffer = 0;

        for (int i = secPtr + 1; i < tang.size(); ++i)
        {
            // 과일이 세 종류가 들어온다면..
            if (tang[i] != secFruit && tang[i] != firFruit)
            {
                // 지금까지의 길이 기록
                answer = max(answer, i - firPtr + buffer);

                // 버퍼 초기화
                buffer = 0;

                firFruit = secFruit;
                firPtr = secPtr;

                secFruit = tang[i];
                secPtr = i;
            }

            // 첫 번째 과일이 들어온다면...
            else if (tang[i] == firFruit)
            {
                buffer += secPtr - firPtr;

                firFruit = secFruit;
                firPtr = secPtr;

                secFruit = tang[i];
                secPtr = i;
            }
        }


        // 1 1 1 2 1 1 3 3 
        //         F   S C       
        // b = 3;
        
        // 1 1 1 2 1 1 3 3 
        //       F S     C      
        // b = 4;
        // 과일이 세 종류가 들어온다면..
        if (tang[N - 1] != secFruit && tang[N - 1] != firFruit)
            answer = max(answer, N - 1 - firPtr + buffer);
        else
            answer = max(answer, N - 1 - firPtr + buffer + 1);


        cout << answer;

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


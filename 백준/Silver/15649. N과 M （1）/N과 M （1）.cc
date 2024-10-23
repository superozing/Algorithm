//////////////////////////////////////////
// N과 M(1)
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
    int N; // 1~N 까지 자연수 중,
    int M; // 중복 없이 M개를 고른 수열 반환 해야 해요.

public:
    void input()
    {
        cin >> N >> M;
    }
    
    void progress()
    {
        for (int i = 1; i <= N; ++i)
        {
            vector<int> visited(11);
            visited[i] = 1;
            backtracking(visited, 1);
        }
    }

    void backtracking(vector<int> visited, int count)
    {
        if (count == M)
        {
            //printvec<bool>(visited);
            for (int i = 1; i <= count; ++i)
            {
                for (int j = 1; j <= N; ++j)
                {
                    if (visited[j] == i)
                    {
                        printf("%d ", j);
                        break;
                    }
                }
            }

            printf("\n");
            return;
        }
        for (int i = 1; i <= N; ++i)
        {
            if (!visited[i])
            {
                vector<int> newVisited = visited;
                newVisited[i] = count + 1;
                backtracking(newVisited, count + 1);
            }
        }
        return;
    }

};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}


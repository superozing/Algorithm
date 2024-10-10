#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    vector<bool> visited(n, false);
    
    for (int j = 0; j < n; ++j)
    {
        // 방문한 컴일 경우 continue;
        if (visited[j])
            continue;
        
        ++answer;
        
        list<int> q;
        visited[j] = true;
        q.push_back(j);

        while (!q.empty())
        {
            int curCom = q.front();
            q.pop_front();

            for (int i = 0; i < n; ++i)
            {
                if (computers[curCom][i] && !visited[i])
                {
                    q.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }
    
    
    return answer;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

void bfs(int start, vector<vector<int>>& com)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < com[cur].size(); ++i)
        {
            if (com[cur][i] && !visited[i])
            {
                visited[i] = true;                
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    visited.resize(n);
    
    for (int i = 0; i < visited.size(); ++i)
    {
        if (!visited[i])
        {
            ++answer;
            bfs(i, computers);
        } 
    }
    
    return answer;
}























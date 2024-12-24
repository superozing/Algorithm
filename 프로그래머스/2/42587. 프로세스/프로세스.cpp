#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    queue<int> q;
    vector<bool> visited(priorities.size());
    
    for (int i = 0; i < priorities.size(); ++i)
        q.push(i);
    
    int progressCnt = 0;
    while (true)
    {
        int cur = q.front();
        q.pop();
        
        bool isValid = true;
        for (int i = 0; i < priorities.size(); ++i)
        {
            if (visited[i])
                continue;
            if (priorities[cur] < priorities[i])
            {
                isValid = false;
                q.push(cur);
                break;
            }
        }
        
        if (isValid)
        {
            ++progressCnt;
            visited[cur] = true;
            if (location == cur)
                return progressCnt;
        }
    }
    
    return 0;
}
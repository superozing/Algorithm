#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct pos
{
    int x, c;
    vector<bool> visited;
};

int getMinMoveCnt(char dest)
{
    return min(dest - 'A', 'Z' - dest + 1);
}

int solution(string name) 
{
    // 각 자릿수 별로 최소 움직임을 기록할 벡터
    vector<int> moveCnt(name.size());
    vector<bool> stdVisited(name.size());
    
    int answer = 0;
    
    // 각 알파벳을 최소 움직임으로 맞추기
    for (int i = 0; i < name.size(); ++i)
    {
        moveCnt[i] = getMinMoveCnt(name[i]);
        
        // 결과 값 누적
        answer += moveCnt[i];    
        
        if (moveCnt[i] == 0)
            stdVisited[i] = true;
        
    }
    
    // 왼 쪽으로 움직이냐 오른 쪽으로 움직이냐... 두 가지 경우가 있다.
    // 왼 쪽으로"만" 움직이거나 오른 쪽으로"만" 움직이거나... 둘 중에 작은 경우를 결과에 더하면 되겠죠?
    
    // 사실 두 가지 경우가 아닐 수도 있잖아요.
    // 이거 bfs 써야겠는걸?
    queue<pos> q;
    stdVisited[0] = true;
    q.push({0, 0, stdVisited});
    
    
    
    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();
        
        bool endFlag = true;
        for (int i = 0; i < cur.visited.size(); ++i)
        {
            if (!cur.visited[i])
            {
                endFlag = false;
                break;
            }
        }
            
        if (endFlag)
            return answer + cur.c;
        
        pos next = cur;
        if (next.x == 0)
        {
            next.x = name.size() - 1;
            next.visited[name.size() - 1] = true;
            next.c++;
            q.push(next);
        }
        else
        {
            next.x--;
            next.visited[next.x] = true;
            next.c++;
            q.push(next);
        }
        
        next = cur;
        if (next.x == name.size() - 1)
        {
            next.x = 0;
            next.visited[0] = true;
            next.c++;
            q.push(next);
        }
        else
        {
            next.x++;
            next.visited[next.x] = true;
            next.c++;
            q.push(next);
        }
        
    }
    
    
    return 0;
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct word
{
    string str;
    vector<bool> visited;
    int cnt;
};

bool canTranslate(string& a, string& b)
{
    int sameCnt = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] == b[i])
            ++sameCnt;
    return sameCnt == a.size() - 1;
}

int solution(string begin, string target, vector<string> words) 
{
    queue<word> q;
    
    word start;
    start.str = begin;
    start.visited.resize(words.size());
    start.cnt = 0;
    
    q.push(start);
    
    while (!q.empty())
    {
        word cur = q.front();
        q.pop();
        
        if (cur.cnt == words.size())
            continue;
        
        for (int i = 0; i < words.size(); ++i)
        {
            if (!cur.visited[i] && canTranslate(words[i], cur.str))
            {
                word next = cur;
                next.str = words[i];
                next.cnt++;
                next.visited[i] = true;
                
                if (next.str == target)
                    return next.cnt;
                
                q.push(next);
            }
        }
    }
    
    return 0;
}




























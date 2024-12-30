#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool> visited;
int maxDungeonCnt = 0;

void dfs(int curCnt, int k, vector<vector<int>>& dungeons);

int solution(int k, vector<vector<int>> dungeons) 
{
    visited.resize(dungeons.size());
    
    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (dungeons[i][0] <= k)
        {
            visited[i] = true;
            dfs(1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
    
    return maxDungeonCnt;
}

void dfs(int curCnt, int k, vector<vector<int>>& dungeons)
{
    maxDungeonCnt = max(maxDungeonCnt, curCnt);
    
    if (curCnt == dungeons.size())
        return;
    
    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (!visited[i] && dungeons[i][0] <= k)
        {
            visited[i] = true;
            dfs(curCnt + 1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
    
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> edges;
vector<bool> visited;

int answer = 101;


int search(vector<int>& w, int max);

int solution(int n, vector<vector<int>> wires) 
{
    edges.resize(n + 1);
    visited.resize(n + 1);
    
    // 송전탑 끼리의 연결 정보를 기록하기.
    for (auto& wire : wires)
    {
        edges[wire[0]].push_back(wire[1]);
        edges[wire[1]].push_back(wire[0]);
    }
    
    // 한 개의 연결이 끊어졌을 때의 연결 수 구하기
    for (auto& wire : wires)
        answer = min(search(wire, n), answer);
    
    return answer;
}


int search(vector<int>& w, int max)
{
    for (int i = 0; i < visited.size(); ++i)
        visited[i] = false;
    
    queue<int> q;
    visited[w[0]] = true;
    q.push(w[0]);
    
    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        
        for (int next : edges[curNode])
        {
            if (!(curNode == w[0] && next == w[1]) && !(curNode == w[1] && next == w[0]) &&
                !visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    
    int linkedCnt = 0;
    for (bool isVisited : visited)
    {
        if (isVisited)
            ++linkedCnt;
    }
    
    //cout << abs(max - linkedCnt - linkedCnt) << endl;
    
    return abs(max - linkedCnt - linkedCnt);
}











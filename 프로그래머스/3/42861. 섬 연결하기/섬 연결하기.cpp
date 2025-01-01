#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> parent;

struct cmp
{
    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        return a[2] < b[2];
    }
};

int Find(int a)
{
    if (parent[a] == a)
        return a;
    
    return parent[a] = Find(parent[a]);
}

bool isCycle(int a, int b)
{
    a = Find(a);
    b = Find(b);

    return a == b;
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    
    if (a != b)
        parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
    int edges = 0;
    
    parent.resize(n);
    // Union-Find 경로 압축을 위한 parent 벡터
    for (int i = 0; i < n; ++i)
        parent[i] = i;
    
    // 크루스칼 알고리즘 사용을 위해 가중치 순으로 정렬
    sort(begin(costs), end(costs), cmp());
    
    // 사이클이 아니면서 cost가 작은 edge 골라 연결
    for (auto& cost : costs)
    {
        if (isCycle(cost[0], cost[1]))
            continue;
        
        Union(cost[0], cost[1]);
        
        answer += cost[2];
        
        ++edges;
        
        if (edges == n - 1)
            break;
    }
    
    return answer;
}




















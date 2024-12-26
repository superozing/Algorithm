#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp
{
    bool operator() (int& a, int& b)
    {
        return a > b;
    }
};

int solution(vector<int> scoville, int K) 
{
    priority_queue<int, vector<int>, cmp> pq;
    
    for (int& i : scoville)
        pq.push(i);
    
    int answer = 0;
    while (pq.size() >= 2 && pq.top() < K)
    {
        int f = pq.top();
        pq.pop();
        
        int s = pq.top();
        pq.pop();
        
        pq.push(f + s * 2);
        
        ++answer;
    }
    
    return pq.top() < K ? -1 : answer;
}
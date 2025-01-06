#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    int val;
    int idx;
};

int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    queue<pos> q;
    
    q.push({numbers[0], 1});
    q.push({-numbers[0], 1});
    
    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();
        
        if (cur.idx == numbers.size())
        {
            if (cur.val == target)
                ++answer;
            continue;
        }
        
        q.push({cur.val + numbers[cur.idx], cur.idx + 1});
        q.push({cur.val - numbers[cur.idx], cur.idx + 1});
    }
    
    return answer;
}
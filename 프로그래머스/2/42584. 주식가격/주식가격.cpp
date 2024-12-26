#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    
    vector<int> answer(prices.size());
    vector<bool> visited(prices.size());
    stack<int> s;
    
    s.push(prices[0]);
    
    // 1 2 3 4 1 3
    // 5 3 2 1 1 0
    
    // 1 3 5 7 9 5 7 9 2 1
    //       2 1 3 2 1    
    
    // 000000
    
    for (int i = 1; i < prices.size(); ++i)
    {
        int curPrice = prices[i];
        if (s.top() > curPrice)
        {
            int popCnt = 1;
            int curIdx = i - 1;
            
            while (!s.empty() && s.top() > curPrice)
            {
                if (!visited[curIdx])
                {
                    visited[curIdx] = true;
                    answer[curIdx] = popCnt;
                    s.pop();
                }
                
                ++popCnt;
                --curIdx;
            }
        }
        
        s.push(prices[i]);
    }
    
    // 마지막에 도달했을 때 스택에 있는 데이터 개수만큼 처음부터 쭉 기록하면
    for (int i = 0; i < answer.size(); ++i)
        answer[i] = answer[i] == 0 ? answer.size() - i - 1 : answer[i];
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    
    int idx = 0;
    
    while (idx < progresses.size())
    {
        int need = 100 - progresses[idx];
        int day = need / speeds[idx];
        
        if (need % speeds[idx] != 0)
            ++day;
        
        for (int i = idx; i < progresses.size(); ++i)
            progresses[i] += speeds[i] * day;
        
        int funcCnt = 0;
        for (int i = idx; i < progresses.size(); ++i)
        {
            if (progresses[i] < 100)
                break;
            
            ++idx;
            ++funcCnt;
        }
        
        answer.push_back(funcCnt);
    }
    
    return answer;
}
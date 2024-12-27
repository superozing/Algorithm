#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    
    for (auto& cmd : commands)
    {
        int s = cmd[0]; // 시작
        int e = cmd[1]; // 끝
        int n = cmd[2]; // n번째
        
        vector<int> cur;
        
        for (int i = s - 1; i < e; ++i)
            cur.push_back(array[i]);
        
        sort(begin(cur), end(cur));
        
        answer.push_back(cur[n - 1]);
    }
    
    return answer;
}
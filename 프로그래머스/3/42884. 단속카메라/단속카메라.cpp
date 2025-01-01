#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct cmp
{
    bool operator()(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
};

int solution(vector<vector<int>> routes) 
{
    int answer = 0;
    
    sort(begin(routes), end(routes), cmp());
    
    int s = -30001, e = -30001;
    
    for (int i = 0; i < routes.size(); ++i)
    {
        int cs = routes[i][0];
        int ce = routes[i][1];
        
        // |            /|            /
        
        if (e < cs)
        {
            s = cs;
            e = ce;
            ++answer;
        }
    }
    
    return answer;
}
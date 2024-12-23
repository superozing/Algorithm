#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int answer = -1;

void search(vector<int>& mats, vector<vector<string>>& park, int y, int x)
{
    for (int mat : mats)
    {
        if (mat + y <= park.size() && mat + x <= park[0].size())
        {
            bool isVaild = true;
            for (int i = y; i < y + mat; ++i)
            {            
                for (int j = x; j < x + mat; ++j)
                {
                    if (park[i][j] != "-1")
                    {    
                        isVaild = false;
                        break;
                    }
                }
                
                if (!isVaild)
                    break;
            }
            
            if (isVaild)
                answer = max(mat, answer);
        }
    }
}

int solution(vector<int> mats, vector<vector<string>> park) 
{
    sort(begin(mats), end(mats));
    
    for (int i = 0; i < park.size(); ++i)
    for (int j = 0; j < park[0].size(); ++j)
    {
        if (park[i][j] != "-1")
            continue;
        
        search(mats, park, i, j);
    }

    return answer;
}
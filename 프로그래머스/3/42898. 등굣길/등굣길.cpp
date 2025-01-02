#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) 
{
    vector<vector<int>> grid(m, vector<int>(n));
    
    for (auto& puddle : puddles)
        grid[puddle[0] - 1][puddle[1] - 1] = -1;

    for (int i = 0; i < m; ++i)
    {
        if (grid[i][0] == -1)
            break;
        
        grid[i][0] = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (grid[0][i] == -1)
            break;
        
        grid[0][i] = 1;
    }
    
    for (int j = 1; j < n; ++j)
    for (int i = 1; i < m; ++i)
    {
        if (grid[i][j] == -1)
            continue;
        
        int upSide = grid[i][j - 1];
        int leftSide = grid[i - 1][j];
        if (upSide != -1)
            grid[i][j] += upSide;
        if (leftSide != -1)
            grid[i][j] += leftSide;
        
        grid[i][j] %= 1'000'000'007;
    }
    
    return grid.back().back();
}
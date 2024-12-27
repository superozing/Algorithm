#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int iMin = 0;
    int iMax = 0;
    
    for (auto& vec : sizes)
    {
        iMin = max(iMin, min(vec[0], vec[1]));
        iMax = max(iMax, max(vec[0], vec[1]));
    }
    
    return iMin * iMax;
}
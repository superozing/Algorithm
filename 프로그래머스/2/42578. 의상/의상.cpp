#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    unordered_map<string, int> um;
    
    for (vector<string>& cloth : clothes)
        um[cloth[1]]++;
    
    int answer = 1;
    
    for (auto& it : um)
        answer *= it.second + 1;
    
    return answer - 1;
}
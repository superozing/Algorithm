#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    unordered_map<string, int> um;
    
    for (string& str : participant)
        um[str]++;
    
        
    for (string& str : completion)
    {
        um[str]--;
        
        if (um[str] == 0)
            um.erase(str);
    }
    
    return um.begin()->first;
}
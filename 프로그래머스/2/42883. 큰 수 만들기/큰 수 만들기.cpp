#include <string>
#include <vector>

using namespace std;

char GetMaxElement(string s, int& k, int& lastIdx)
{
    char c = 0;
    int maxIdx = 0;
    
    for (int i = 0; i <= k; ++i)
    {
        if (s[i] > c)
        {
            maxIdx = i;
            c = s[i];
        }
    }
    
    k -= maxIdx;
    lastIdx += maxIdx + 1;
    return c;
}

string solution(string number, int k) 
{
    string answer;
    int lastIdx = 0;
    
    while (k > 0 && lastIdx + k < number.size())
        answer += GetMaxElement(number.substr(lastIdx), k, lastIdx);
    
    answer += number.substr(lastIdx);
    
    while (k-- > 0)
        answer.pop_back();
    
    return answer;
}
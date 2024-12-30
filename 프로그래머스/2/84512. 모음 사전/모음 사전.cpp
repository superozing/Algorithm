#include <string>
#include <vector>
#include <iostream>

using namespace std;

void next(string& cur)
{
    if (cur.length() == 5 && cur.back() == 'U')
    {
        while (cur.back() == 'U')
            cur.pop_back();
        
        switch (cur.back())
        {
            case 'A':
                cur.back() = 'E';
                break;
            case 'E':
                cur.back() = 'I';
                break;
            case 'I':
                cur.back() = 'O';
                break;
            case 'O':
                cur.back() = 'U';
                break;
        }
        
        return;
    }
    
    else if (cur.length() == 5)
    {
        switch (cur.back())
        {
            case 'A':
                cur.back() = 'E';
                break;
            case 'E':
                cur.back() = 'I';
                break;
            case 'I':
                cur.back() = 'O';
                break;
            case 'O':
                cur.back() = 'U';
                break;
        }
        
        return;
    }
    
    else
        cur += 'A';
    
    return;
}

int solution(string word) 
{
    int answer = 1;
    string cur = "A";
    
    while (word != cur)
    {
        //cout << cur << endl;
        ++answer;
        next(cur);
    }
    
    return answer;
}
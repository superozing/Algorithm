#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int parenthesisCnt = 0;
    for (char c : s)
    {
        switch (c)
        {
        case '(':
            ++parenthesisCnt;
            break;
        case ')':
            if (parenthesisCnt == 0)
                return false;
            --parenthesisCnt;
            break;
        }
    }
    
    return parenthesisCnt == 0;
}
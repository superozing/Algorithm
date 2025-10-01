#include <iostream>

using namespace std;

int main()
{
    int answer = 0;
    
    int minvalue = 101;
    
    int in;
    for (int i = 0; i < 4; ++i)
    {
        cin >> in;
        answer += in;
        minvalue = min(minvalue, in);
    }
    
    answer -= minvalue;
    
    minvalue = 101;
    for (int i = 0; i < 2; ++i)
    {
        cin >> in;
        answer += in;
        minvalue = min(minvalue, in);
    }
    answer -= minvalue;
    
    cout << answer;
    
    return 0;
}
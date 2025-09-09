#include <iostream>

using namespace std;

int main()
{
    bool visited[31]{};
    
    for (int i = 0; i < 28; ++i)
    {
        int idx;
        cin >> idx;
        
        visited[idx] = true;
    }
    
    for (int i = 1; i <= 30; ++i)
    {
        if (!visited[i])
            cout << i << '\n';
    }   
    
    return 0;
}
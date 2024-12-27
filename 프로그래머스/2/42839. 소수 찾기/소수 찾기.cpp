#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

string s;
string numbers;
vector<bool> visited;
set<string> permutation;
vector<bool> isDemical;
int answer = 0;

void backtracking()
{
    if (permutation.find(s) == permutation.end())
    {
        permutation.insert(s);
        if (isDemical[stoi(s)])
            ++answer;
    }
    else
        return;
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (visited[i])
            continue;
        
        visited[i] = true;
        s += numbers[i];
        backtracking();
        visited[i] = false;
        s.pop_back();
    }
}

int solution(string strnums) 
{
    numbers = strnums;
    // 소수 + 백트래킹
    isDemical.resize(10000000, true);
    
    isDemical[0] = false;
    isDemical[1] = false;
    for (int i = 2; i < sqrt(isDemical.size()); ++i)
    {
        if (isDemical[i])
        {
            for (int j = i + i; j < isDemical.size(); j += i)
                isDemical[j] = false;
        }
    }

    visited.resize(strnums.size());
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] == '0')
            continue;
        
        visited[i] = true;
        s += numbers[i];
        backtracking();
        visited[i] = false;
        s.pop_back();
    }
    
    return answer;
}
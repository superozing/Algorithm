#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) 
{
    multiset<int> pq;
    
    for (string& s : operations)
    {
        char oper = s[0];
        int num = stoi(s.substr(1, s.size() - 1));
        
        switch (oper)
        {
        case 'I' :
            pq.insert(num);
            break;
                
        case 'D' :
            
            // 데이터 개수가 0이면 아무 동작을 하지 않아요.
            if (pq.empty())
                break;
            
            if (num == 1)
                pq.erase(*rbegin(pq));
            else
                pq.erase(*begin(pq));
            
            break;
        }
    }
    
    if (pq.empty())
        return vector<int>(2);
    else
        return vector<int>{*rbegin(pq), *begin(pq)};
}
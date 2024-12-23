#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool cmp(string& a, string& b)
{
    return a.length() == b.length() ? a < b : a.length() < b.length();
}

bool solution(vector<string> phone_book) 
{
    sort(begin(phone_book), end(phone_book), cmp);
    unordered_set<string> us;
    
    for (string& s : phone_book)
    {
        // s의 문자 개수를 1개부터 s.length()개 까지 늘려가면서 us에 있는지 검사하면 어떨까요?
        for (int i = 1; i < s.length(); ++i)
        {
            if (us.find(s.substr(0, i)) != us.end())
                return false;
        }
        
        us.insert(s);
    }
    
    return true;
}
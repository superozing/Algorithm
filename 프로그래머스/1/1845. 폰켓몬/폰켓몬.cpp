#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> us;
    
    for (int i : nums)
        us.insert(i);
    
    return us.size() > nums.size() / 2 ? nums.size() / 2 : us.size();
}
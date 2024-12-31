#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) 
{
    // 투 포인터를 사용한다면 간단하게 해결할 수 있지 않을까요?
    
    // 일단 정렬을 하고,
    // 왼 쪽에서 한 개 고르고 오른 쪽 부터 무게 제한을 넘지 않을 때 까지 오른 쪽 포인터를 -- 해주면 될 것 같아요.
    
    int answer = 0;
    sort(begin(people), end(people));

    int l = 0;
    int r = people.size() - 1;
    
    while (l <= r)
    {
        //cout << "l: " << l << ", r: " << r << endl;
        //cout << "people[l]: " <<people[l] << ", people[r]: " << people[r] << endl;
        
        if (people[l] + people[r] <= limit)
            ++l;
        --r;
        ++answer;
    }
    
    
    return answer;
}
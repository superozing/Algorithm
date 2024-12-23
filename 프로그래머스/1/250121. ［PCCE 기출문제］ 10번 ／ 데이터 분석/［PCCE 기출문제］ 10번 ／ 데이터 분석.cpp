#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum index
{
    code,
    date,
    maximum,
    remain,
};

index idx1;
index idx2;

bool cmp1(vector<int>& a, vector<int>& b)
{
    return a[(int)idx1] < b[(int)idx1];
}

bool cmp2(vector<int>& a, vector<int>& b)
{
    return a[(int)idx2] < b[(int)idx2];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    if (ext == "code")
        idx1 = code;
    else if (ext == "date")
        idx1 = date;
    else if (ext == "maximum")
        idx1 = maximum;
    else
        idx1 = remain;
    
    sort(begin(data), end(data), cmp1);
    
    if (sort_by == "code")
        idx2 = code;
    else if (sort_by == "date")
        idx2 = date;
    else if (sort_by == "maximum")
        idx2 = maximum;
    else
        idx2 = remain;
    
    while (data.back()[(int)idx1] > val_ext)
        data.pop_back();
    
    sort(begin(data), end(data), cmp2);
    
     return data;
}
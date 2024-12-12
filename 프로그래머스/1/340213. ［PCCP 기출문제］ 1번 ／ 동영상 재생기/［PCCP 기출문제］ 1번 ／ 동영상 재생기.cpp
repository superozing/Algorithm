#include <string>
#include <vector>
#include <iostream>

using namespace std;

int timeToInt(string& s)
{
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

string intToTime(int i)
{
    string min = to_string(i / 60);
    string sec = to_string(i % 60);
    
    if (min.length() == 1)
        min = '0' + min;
    if (sec.length() == 1)
        sec = '0' + sec;
    
    return min + ':' + sec;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) 
{
    int iVideo_len = timeToInt(video_len);
    int iPos = timeToInt(pos);
    int iOp_start = timeToInt(op_start);
    int iOp_end = timeToInt(op_end); 
    
    // 오프닝 건너뛰기
    if (iPos >= iOp_start && iPos < iOp_end)
        iPos = iOp_end;
    
    for (string& s : commands)
    {
        if (s == "next")
            iPos = iPos + 10 > iVideo_len ? iVideo_len : iPos + 10;
        else
            iPos = iPos < 10 ? 0 : iPos - 10;
        
        // 오프닝 건너뛰기
        if (iPos >= iOp_start && iPos < iOp_end)
            iPos = iOp_end;
    }
    
    return intToTime(iPos);
}
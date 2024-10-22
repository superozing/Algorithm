////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

class Boj
{
private:
    string str1;
    string str2;

public:
    void input()
    {
        cin >> str1 >> str2;
    }

    void progress()
    {
        vector<vector<int>> lcs(str1.length() + 1, vector<int>(str2.length() + 1));

        for (int i = 1; i < lcs.size(); ++i)
        {
            for (int j = 1; j < lcs[0].size(); ++j)
            {
                
                // 두 문자열을 한 글자씩 비교
                if (str1[i - 1] == str2[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1; // 두 문자가 같을 경우, 지금까지의 최대 공통 부분 수열에 +1
                else
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]); // 두 문자가 다를 경우, 지금까지 증가 유지
                //cout << lcs[i][j] << ' ';
            }
            //cout << endl;
        }

        cout << lcs.back().back();
    }

};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}

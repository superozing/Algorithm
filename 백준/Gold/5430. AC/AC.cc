///////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cmath>

using namespace std;

#define endl ("\n")

class Boj
{
private:
    int T;

public:

    void input()
    {
        cin >> T;
    }

    void progress()
    {
        while (T--)
            AC();
    }

private:

    void AC()
    {
        string cmd;
        int eleCnt;
        string arr;
        list<int> nums;
        bool isAssending = true;

        // 세 가지를 해야겠죠?
        // 1. 파싱
        //  getline()으로 받아온 배열을 nums에 넣어주어야 한다.
        //  첫 글자는 건너 뛰고... ','가 나올 때 까지 r을 옮기고 l부터 stoi(substr()) 써서 숫자 구하면 될 것 같아요.
        //  순서대로 리스트에 넣으면 되겠죠?
        // 2. 명령어 수행
        //  R일 경우, isAssending = !isAssending 해요.
        //  D일 경우, isAssending? pop_front() : pop_back(); => nums.empty()? 예외처리.
        // 3. 출력

        cin >> cmd;
        cin >> eleCnt;
        cin >> arr;

        for (int l = 1, r = 2; r < arr.size(); ++r)
        {
            if (arr[r] == ',' || arr[r] == ']')
            {
                nums.push_back(stoi(arr.substr(l, r - l)));
                l = r + 1;
            }
        }

        for (int i = 0; i < cmd.size(); ++i)
        {
            switch (cmd[i])
            {
            case 'R':
                isAssending = !isAssending;
                break;

            case 'D':
                if (nums.empty())
                {
                    cout << "error" << endl;
                    return;
                }
                isAssending ? nums.pop_front() : nums.pop_back();
                break;
            }
        }

        int size = nums.size() - 1;
        cout << '[';
        if (isAssending)
        {
            for (int it : nums)
            {
                cout << it;
                if (size--)
                    cout << ',';
            }
        }
        else
        {
            for (auto it = nums.rbegin(); it != nums.rend(); ++it)
            {
                cout << *it;
                if (size--)
                    cout << ',';
            }
        }
        cout << ']' << endl;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}


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
#include <cmath>

using namespace std;

class Boj
{
private:

public:

    void input()
    {
    }

    void progress()
    {
        bool isInvalid;
        string str;

        while (true)
        {
            stack<char> s;

            getline(cin, str);

            //cout << str << endl;

            // 종료 조건
            if (str == ".")
                return;

            isInvalid = false;

            // 문자열을 순회하며 괄호의 균형이 맞는지 체크해요.
            for (char c : str)
            {
                switch (c)
                {
                case '(':
                case '[':
                    s.push(c);
                    break;

                case ')':
                    if (s.empty() || s.top() != '(')
                    {
                        isInvalid = true;
                        break;
                    }
                    s.pop();
                    
                    break;

                case ']':
                    if (s.empty() || s.top() != '[')
                    {
                        isInvalid = true;
                        break;
                    }
                    s.pop();

                    break;
                }
            }

            if (!s.empty())
                isInvalid = true;

            // 두 괄호 모두 올바른 괄호 문자열 인가요?
            cout << (isInvalid ? "no\n": "yes\n");
        }
    }

private:

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


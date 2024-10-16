// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>

using namespace std;

struct Trie
{
    // 음...
    // 일단 배열로 가능한가?

    // 입력 예시 기준 n 개의 데이터를 전부 트라이에 넣어놓고
    // 다른 입력으로 들어오는 m 개의 데이터를 트라이를 순회하면서 substring인지 검사하면 될 것 같아요.
    Trie* child[26];
    bool finish; // 마지막 데이터 인가?

    void insert(const char* str)
    {
        // 입력으로 들어온 문자가 null문자면 문자열의 마지막 트라이에요..
        if (*str == '\0')
            finish = true;
        else
        {
            int cur = *str - 'a';

            // 자식 트라이가 없을 경우 힐딩해요.
            if (child[cur] == nullptr)
                child[cur] = new Trie();

            child[cur]->insert(str + 1); // 다음 문자로 이동 (주소 연산)
        }
    }

    bool find(const char* str)
    {
        // 만약 str의 마지막 글자까지 전부 도달한 경우
        if (*str == '\0')
            return true;
        
        int cur = *str - 'a';

        // 자식 트라이가 없을 경우 찾기 실패 해요.
        if (child[cur] == nullptr)
            return false;

        return child[cur]->find(str + 1); // 다음 문자로 find (주소 연산)
    }

    Trie()
        : finish(false)
        , child{}
    {
    }

    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
        {
            if (child[i])
                delete child[i];
        }
    }
};

class Boj
{
public:
    int n;
    int m;
    Trie* root;


    int progress()
    {
        int ret = 0;
        cin >> n >> m;

        root = new Trie;

        // insert()
        for (int i = 0; i < n; ++i)
        {
            string input;
            cin >> input;
            root->insert(input.c_str());
        }

        // find()
        for (int i = 0; i < m; ++i)
        {
            string input;
            cin >> input;
            if (root->find(input.c_str()))
                ++ret;
        }

        return ret;
    }

private:

};

int main()
{
    Boj boj;
    cout << boj.progress();

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

struct Trie
{
    Trie* next[26];
    bool finish;

    void insert(const char* str)
    {
        if (*str == '\0')
        {
            finish = true;
            return;
        }

        int idx = *str - 'a';

        if (!next[idx])
            next[idx] = new Trie;

        return next[idx]->insert(str + 1);
    }

    bool find(const char* str)
    {
        if (*str == '\0')
        {
            return finish;
        }

        int idx = *str - 'a';

        if (!next[idx])
            return false;

        return next[idx]->find(str + 1);
    }

    Trie() 
        : finish(false) 
    {
        for (int i = 0; i < 26; ++i)
            next[i] = nullptr;
    }
    ~Trie() {}

};

class Boj
{
private:
    Trie* root;
    int N, M;

public:
    void input()
    {
        cin >> N >> M;
        root = new Trie;

        string s;
        for (int i = 0; i < N; ++i)
        {
            cin >> s;
            root->insert(s.c_str());
        }
    }

    void progress()
    {
        int answer = 0;
        string s;
        for (int i = 0; i < M; ++i)
        {
            cin >> s;
            if (root->find(s.c_str()))
                ++answer;
        }

        cout << answer;
    }
};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}

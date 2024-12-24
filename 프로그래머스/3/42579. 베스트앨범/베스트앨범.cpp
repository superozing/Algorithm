#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Music
{
    int idx;
    int play;
};

struct Genre
{
    int acc;
    vector<Music> music;
};

bool musicCmp(Music& a, Music& b)
{
    return a.play == b.play ? a.idx < b.idx : a.play > b.play;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    // 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
    unordered_map<string, Genre> genreMap;
    
    for (int i = 0; i < genres.size(); ++i)
    {
        genreMap[genres[i]].acc += plays[i];
        genreMap[genres[i]].music.push_back({i, plays[i]});
    }
    
    //////////
    
    vector<int> answer;
    
    map<int, string> accPlay;
    
    for (auto& it : genreMap)
        accPlay.insert({it.second.acc, it.first});

    for (auto it = accPlay.rbegin(); it != accPlay.rend(); ++it)
    {
        auto& cur = genreMap[it->second];
        sort(begin(cur.music), end(cur.music), musicCmp);
        
        answer.push_back(cur.music[0].idx);
        if (cur.music.size() != 1)
            answer.push_back(cur.music[1].idx);
    }
    
    return answer;
}
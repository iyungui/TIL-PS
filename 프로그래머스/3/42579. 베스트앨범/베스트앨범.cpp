#include <bits/stdc++.h>

using namespace std;

struct Song {
    int totalByGenre;
    string genre;
    int cnt;
    int idx;
};

bool cmp(const Song& a, const Song& b) {
    // 속한 노래가 많이 재생된 장르부터
    if(a.totalByGenre != b.totalByGenre) return a.totalByGenre > b.totalByGenre;
    // 장르 내에서 많이 재생된 노래부터
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    // 고유번호가 낮은 노래부터
    return a.idx < b.idx;
}

vector<Song> songs;

unordered_map<string, int> mp;

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = genres.size();
    for(int i = 0; i < n; i++) {
        mp[genres[i]] += plays[i];  // 장르별로 카운트만 먼저
    }
    for(int i = 0; i < n; i++) {
        songs.push_back({mp[genres[i]], genres[i], plays[i], i});
    }
    
    sort(songs.begin(), songs.end(), cmp);
    
    vector<int> answer;
    // 장르별로 두 개씩만
    unordered_map<string, int> mp2;
    for(int i = 0; i < n; i++) {
        if(mp2[songs[i].genre] < 2) {
            mp2[songs[i].genre]++;
            answer.push_back(songs[i].idx);
        }
    }
    return answer;
}
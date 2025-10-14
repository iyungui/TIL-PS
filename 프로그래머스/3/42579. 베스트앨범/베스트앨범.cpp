#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genre_play_count;
    unordered_map<string, vector<pair<int, int>>> genre_songs;

    for (int i = 0; i < genres.size(); i++) {
        genre_play_count[genres[i]] += plays[i];
        genre_songs[genres[i]].emplace_back(plays[i], i);
    }

    // Sort genres by total play count in descending order
    vector<pair<int, string>> sorted_genres;

    for (const auto& entry : genre_play_count) {
        sorted_genres.emplace_back(entry.second, entry.first);
    }

    sort(sorted_genres.rbegin(), sorted_genres.rend());

    // For each genre, sort songs by play count (and index for ties) and select top two songs
    for (const auto& genre_entry : sorted_genres) {
        const string& genre = genre_entry.second;
        auto& songs = genre_songs[genre];

        sort(songs.begin(), songs.end(), cmp);

        for (int i = 0; i < min(2, (int)songs.size()); i++) {
            answer.push_back(songs[i].second);
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};
    vector<int> result = solution(genres, plays);

    for (int i : result) {
        cout << i << " ";
    }
    
    cout << '\n';
     
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct Team {
    int idx;
    int sum = 0;
    int cnt = 0;
    int five;
};

int cnt[204];

int solution(int n, vector<int> arr) {
    memset(cnt, 0, sizeof(cnt));
    vector<Team> teams(n+1);
    // 팀별로 선수 세기
    for(int i = 1; i <= n; i++) cnt[arr[i]]++;
    for(int i = 1; i <= n; i++) teams[i].idx = i;
    
    int rank = 1;
    for(int i = 1; i <= n; i++) {
        int team_id = arr[i];
        // 여섯 명 안되면 패스
        if(cnt[team_id] < 6) continue;
        teams[team_id].cnt++;
        if(teams[team_id].cnt == 5) teams[team_id].five = rank;
        if(teams[team_id].cnt <= 4) teams[team_id].sum += rank;
        rank++;
    }

    vector<Team> valid_teams;
    for(int i = 1; i <= 200; i++) {
        if(cnt[i] == 6) valid_teams.push_back(teams[i]);
    }

    sort(valid_teams.begin(), valid_teams.end(), [](const auto& a, const auto& b) {
        if(a.sum != b.sum) return a.sum < b.sum;
        return a.five < b.five;
    });

    return valid_teams[0].idx;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<int> input(n+1);
        for(int i = 1; i <= n; i++) cin >> input[i];
        int win_team_id = solution(n, input);
        cout << win_team_id << '\n';
    }
    return 0;
}
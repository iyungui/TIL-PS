#include<bits/stdc++.h>

using namespace std;

int a[54][54];
int ret = INT_MAX, n, m;
vector<pair<int, int>> chickens, homes;

int go(vector<int> selected) {
    int cityDist = 0;
    for(int i = 0; i < homes.size(); i++) {
        int dist = INT_MAX;
        for(int j : selected) {
            int s = abs(homes[i].first - chickens[j].first) + abs(homes[i].second - chickens[j].second);
            dist = min(s, dist);
        }
        cityDist += dist;
    }
    return cityDist;
}

void solve(int here, vector<int> &b) {
    if(b.size() == m) {
        ret = min(ret, go(b));
        return;
    }
    for(int i = here + 1; i < chickens.size(); i++) {
        b.push_back(i);
        solve(i, b);
        b.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) homes.push_back({i, j});
            if(a[i][j] == 2) chickens.push_back({i, j});
        }
    }
    vector<int> b;
    solve(-1, b);
    cout << ret << '\n';
}
#include <bits/stdc++.h>

using namespace std;

int n, m, a[54][54];
vector<pair<int, int>> chicken, _home;
vector<vector<int>> chickenList;

void combi(int start, vector<int> & v) {
    if(v.size() == m) {
        chickenList.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) chicken.push_back({i, j});
            if(a[i][j] == 1) _home.push_back({i, j});
        }
    }
    
    vector<int> v;
    combi(-1, v);
    int ans = INT_MAX;
    for(vector<int> cList : chickenList) {
        int sum = 0;
        for(pair<int, int> home : _home) {
            int c_dist = INT_MAX, _dist;
            for(int c : cList) {
                _dist = abs(home.first - chicken[c].first) + abs(home.second - chicken[c].second);
                c_dist = min(c_dist, _dist);
            }
            sum += c_dist;
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}

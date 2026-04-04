#include<bits/stdc++.h>
using namespace std;

int d[204][204];
int a[204];
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF; 
        }
    }
    for(int i = 0; i < m; i++) {
        int a, b, t; cin >> a >> b >> t;
        d[a][b] = min(d[a][b], t);
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }


    int K; cin >> K;
    for(int i = 0; i < K; i++) cin >> a[i];
    vector<pair<int, int>> ret;
    int min_of_max = INF;
    for(int x = 1; x <= n; x++) {
        int max_dist = 0;
        bool flag = 1;

        for(int i = 0; i < K; i++) {
            if(d[a[i]][x] == INF || d[x][a[i]] == INF) {
                flag = 0;
                break;
            }
            max_dist = max(max_dist, d[a[i]][x] + d[x][a[i]]);
        }
        if(flag) {
            ret.push_back({max_dist, x});
            min_of_max = min(min_of_max, max_dist);
        }
    }
    for(auto res : ret) {
        if(res.first == min_of_max) cout << res.second << ' '; 
    }
    cout << '\n';
    return 0;
}
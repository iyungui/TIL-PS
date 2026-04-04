#include<bits/stdc++.h>
using namespace std;

int a[100004];
// i번째 단계. L. R 위치까지 가는 최소 힘
int d[100004][5][5];

int get_score(int from, int to) {
    if(from == 0) return 2;
    if(from == to) return 1;
    if(abs(from - to) == 2) return 4;
    return 3;
}
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 0;
    while(1) {
        int num; cin >> num; if(num == 0) break;
        a[n++] = num;
    }
    memset(d, 0x3f, sizeof(d));
    d[0][0][0] = 0;
    for(int i = 0; i < n; i++) {
        int t = a[i];
        for(int l = 0; l < 5; l++) {
            for(int r = 0; r < 5; r++) {
                // 도달 불가능한 상태
                if(d[i][l][r] == INF) continue;
                // left
                if(t != r) d[i+1][t][r] = min(d[i+1][t][r], get_score(l, t) + d[i][l][r]);
                // right
                if(t != l) d[i+1][l][t] = min(d[i+1][l][t], get_score(r, t) + d[i][l][r]);
            }
        }
    }

    int ans = INF;
    for(int l = 0; l < 5; l++) {
        for(int r = 0; r < 5; r++) {
            ans = min(ans, d[n][l][r]);
        }
    }
    cout << ans << '\n';
    return 0;
}
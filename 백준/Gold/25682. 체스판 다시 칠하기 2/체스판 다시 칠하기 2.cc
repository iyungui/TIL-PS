#include<bits/stdc++.h>
using namespace std;

int a[2004][2004];
int d[2004][2004];    // d[i][j] = (1,1) 부터 (i,j)까지 다시 칠해야하는 칸의 개수
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c; cin >> c;
            a[i][j] = (c == 'W') ? 0 : 1;
        }
    }
    // 첫번째 칸이 W라면 (i+j)의 칸도 'W'여야 한다. 다르다면 1
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int t = ((i+j)%2) ^ a[i][j];
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + t;
        }
    }

    int ret = 1e9;
    for(int i = k; i <= n; i++) {
        for(int j = k; j <= m; j++) {
            int cnt = d[i][j] - d[i-k][j] - d[i][j-k] + d[i-k][j-k];
            int cnt2 = k*k - cnt;
            ret = min({ret, cnt, cnt2});
        }
    }
    cout << ret << '\n';
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int d[104][104];
int item[104];
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) {
        cin >> item[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for(int i = 0; i < r; i++) {
        int a, b, l; cin >> a >> b >> l;
        d[a][b] = min(d[a][b], l);
        d[b][a] = min(d[b][a], l);
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            if(d[i][j] <= m) sum += item[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}
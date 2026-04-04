#include<bits/stdc++.h>
using namespace std;

int n[404];
int d[404][404];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        d[a][b] = -1;
        d[b][a] = 1;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            if(d[i][k] == 0) continue;
            for(int j = 1; j <= n; j++) {
                if(d[i][k] == -1 && d[k][j] == -1) d[i][j] = -1;
                if(d[i][k] == 1 && d[k][j] == 1) d[i][j] = 1;
            }
        }
    }
    int s; cin >> s;
    for(int i = 0; i < s; i++) {
        int a, b; cin >> a >> b;
        cout << d[a][b] << '\n';
    }
    return 0;
}
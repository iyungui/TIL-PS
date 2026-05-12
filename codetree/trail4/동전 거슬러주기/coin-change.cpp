#include <bits/stdc++.h>
using namespace std;

int n, m;
int coins[104];
// i원을 만들기위한 최소 동전의 수
int d[10004];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> coins[i];
    memset(d, 0x3f3f3f3f, sizeof(d));
    d[0] = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= coins[j]) {
                if(d[i-coins[j]] == 0x3f3f3f3f) continue;
                d[i] = min(d[i], d[i - coins[j]] + 1);
            }
        }
    }
    if(d[m] == 0x3f3f3f3f) cout << -1 << '\n';
    else cout << d[m] << '\n'; 
    return 0;
}
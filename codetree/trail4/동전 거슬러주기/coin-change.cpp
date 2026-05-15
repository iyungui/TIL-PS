#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[10004];   // d[i]: i원을 거슬러주기 위해 필요한 최소 동전의 수

int main() {
    cin >> n >> m;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    // 최솟값을 구해야하므로 최댓값부터
    for(int i = 0; i <= m; i++) d[i] = INT_MAX;
    d[0] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            if(i - coins[j] >= 0) {
                if(d[i-coins[j]] == INT_MAX) continue;  // i-coins[j]원을 거슬러줄 수 없는 경우 
                d[i] = min(d[i], d[i-coins[j]] + 1);
            }
        }
    }
    if(d[m] == INT_MAX) cout << -1 << '\n';
    else cout << d[m] << '\n';
    return 0;
}
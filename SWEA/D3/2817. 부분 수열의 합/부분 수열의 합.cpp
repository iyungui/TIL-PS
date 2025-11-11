#include<bits/stdc++.h>

using namespace std;

int T, n, k, a[24];

int solve() {
    int dp[1001] = {0};
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = k; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
        }
    }
    return dp[k];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;

    for(int t = 1; t <= T; t++) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << "#" << t << " " << solve() << '\n';
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int T, n, k;
int a[24], dp[24][1004];

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n >> k;

        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n; i++) cin >> a[i];

        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i][j] = dp[i-1][j];
                if(j >= a[i]) dp[i][j] += dp[i-1][j - a[i]];
            }
        }
         
        cout << "#" << t << " " << dp[n][k] << '\n';
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int T, n, k;
int dp[1004];
int a[24];

int main() {
    cin >> T;

    for(int t = 1; t <= T; t++) {
        cin >> n >> k;

        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));

        for(int i = 0; i < n; i++) cin >> a[i];


        dp[0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = k; j >= a[i]; j--) {
                dp[j] += dp[j - a[i]];
            }
        }

        cout << "#" << t << " " << dp[k] << '\n';
    }

    return 0;
}
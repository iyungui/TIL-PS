#include<bits/stdc++.h>
using namespace std;

int n, ret;
int dp[501][501], a[501][501];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    dp[0][0] = a[0][0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
                // 오른쪽 위에 경로만
                dp[i][j] = dp[i-1][j] + a[i][j];
            }
            else if(j == i) {
                // 왼쪽 위에 경로만
                dp[i][j] = dp[i-1][j-1] + a[i][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
            }
        }
    }
    for(int j = 0; j < n; j++) {
        ret = max(ret, dp[n-1][j]);
    }
    cout << ret << '\n';
    return 0;
}
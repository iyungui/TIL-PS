#include <bits/stdc++.h>
using namespace std;
// Sa - Sb = j
// (Sa + x) - Sb = j
// Sa - (Sb + x) = j
int main() {
    int n; cin >> n;
    int m = 0;  // total
    vector<int> nums(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        m += nums[i];
    }
    // dp[i][j] = i번째 수까지 고려, A-B가 j일때, A의 최대합
    vector<vector<int>> dp(n+1, vector<int>(2*m+1, -1));
    dp[0][m] = 0;

    // C에 버리는 경우 -> 이전상태 그대로
    // dp[i][j] = dp[i-1][j]
    
    // A에 넣는 경우 -> i-1번째 수까지 고려했을때, 차이가 j-nums[i]였어야함
    // dp[i][j] = dp[i-1][j-num[i]] + nums[i]

    // B에 넣는 경우
    // dp[i][j] = dp[i-1][j+nums[i]]

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 2*m; j++) {
            if(dp[i-1][j] != -1) dp[i][j] = max(dp[i][j], dp[i-1][j]);

            if(j -nums[i] >= 0 && dp[i-1][j-nums[i]] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-nums[i]] + nums[i]);
            }

            if(j+nums[i] <= 2*m && dp[i-1][j+nums[i]] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j+nums[i]]);
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
} 
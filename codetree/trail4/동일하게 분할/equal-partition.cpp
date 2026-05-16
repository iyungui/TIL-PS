#include <bits/stdc++.h>
using namespace std;
// A-B가 0 이어야함
int n;
/*
i번째 수까지 고려, A-B 가 j 라면 true, 아니라면 false

i번째 수를 A에 넣는 경우
dp[i][j] = true (단 dp[i-1][j-nums[i]] 가 true)

i번째 수를 넣지않는경우(B에 넣는경우)
dp[i][j] = true (단 dp[i-1][j+nums[i]] 가 true)

*/
int main() {

    cin >> n;
    vector<int> nums(n+1);
    int m = 0;
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        m += nums[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(2*m+1, false));
    dp[0][m] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 2*m; j++) {
            if(j-nums[i] >= 0 && dp[i-1][j-nums[i]]) dp[i][j] = true;
            if(j+nums[i] <= 2*m && dp[i-1][j+nums[i]]) dp[i][j] = true;
        }
    }

    if(dp[n][0 + m]) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
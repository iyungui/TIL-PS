#include <bits/stdc++.h>
using namespace std;

// i번째 수를 마지막으로 하고, 음수를 j개 포함한 연속부분수열의 최대합
// dp[i][j]
const int INF = -1e9;
int main() {
    int n, k; cin >> n >> k;
    vector<int> nums(n+1);
    for(int i = 1; i <= n; i++) cin >> nums[i];
    vector<vector<int>> dp(n+1, vector<int>(k+1, INF));
    
    // 숫자를 포함하지 않는 경우
    dp[0][0] = 0;
    // 숫자 1개만 포함하는 경우
    for(int i = 1; i <= n; i++) {
        if(nums[i] < 0) dp[i][1] = nums[i];
        if(nums[i] >= 0) dp[i][0] = nums[i];
    }
    // 나머지 dp 테이블 채우기
    for(int i = 1; i <= n; i++) {
        int x = nums[i];
        for(int j = 0; j <= k; j++) {
            // i번째 수가 양수인 경우
            if(x >= 0) {
                // 이전상태가 존재하는 경우
                if(dp[i-1][j] != INF) dp[i][j] = max(dp[i][j], dp[i-1][j] + x);
            }
            // i번째 수가 음수인 경우
            else if(x < 0) {
                // 이전상태가 존재하는 경우
                if(j > 0 && dp[i-1][j-1] != INF) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + x);
            }
        }
    }
    // dp테이블 중 최댓값
    int ret = INF;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            ret = max(ret, dp[i][j]);
        }
    }
    cout << ret << '\n';
    return 0;
}
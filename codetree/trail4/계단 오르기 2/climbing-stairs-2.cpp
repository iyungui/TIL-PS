#include <bits/stdc++.h>
using namespace std;

// dp[i][j] = i층 높이까지 1계단오르는 행위를 j번 했을때, 얻을 수 있는 동전의 최대개수
int n;
int m = 3;
int main() {
    cin >> n;
    vector<int> coins(n+1);
    for(int i = 1; i <= n; i++) cin >> coins[i];
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            // i층 높이에 오르기 전에, i-1층에서 1단계 올랐을 경우
            if(j > 0 && dp[i-1][j-1] != -1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + coins[i]);
            // i층 높이에 오르기 전에, i-2층에서 2단계 올랐을 경우
            if(i >= 2 && dp[i-2][j] != -1) dp[i][j] = max(dp[i][j], dp[i-2][j] + coins[i]);
        }
    }
    int ret = *max_element(dp[n].begin(), dp[n].end());

    // n층에 도달하지 못하는 경우
    if(ret == -1) cout << 0 << '\n';
    else cout << ret << '\n';
    return 0;
}
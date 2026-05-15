#include <bits/stdc++.h>
using namespace std;

// 중복 사용 ok
int n, m, dp[100004]; // dp[i] 합 i를 만드는 최대 동전의 수
int main() {
    cin >> n >> m;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    // 최대값을 구해야하므로 최소값부터.(dp[i] 가 -1 라면, 합 i를 만들 수 없다는 뜻)
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            int x = coins[j];
            if(i - x < 0) continue;
            if(dp[i - x] == -1) continue;
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
    }

    cout << dp[m] << '\n';
    return 0;
}
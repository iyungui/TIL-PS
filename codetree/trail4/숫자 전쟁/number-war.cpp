#include <bits/stdc++.h>
using namespace std;

// dp[i][j] = A가 i장, B(나)가 j장의 카드를 버렸을 때, 내가 얻을 수 있는 최대점수

int main() {
    int n; cin >> n;
    vector<int> A(n+1); // 첫번째플레이어
    vector<int> B(n+1); // 두번째플레이어
    for(int i = 1; i <= n; i++) cin >> A[i];
    for(int i = 1; i <= n; i++) cin >> B[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    dp[0][0] = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][j] == -1) continue;

            // 둘 다 카드를 버리는 경우 또는 비기는 경우
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);

            // 대결하는 경우
            // A가 이기는 경우(A만 버림)
            if(A[i+1] < B[j+1]) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            } 
            // B가 이기는 경우(B만 버림 + 점수 획득)
            else if(A[i+1] > B[j+1]) {
                dp[i][j+1] = max(dp[i][j+1], dp[i][j] + B[j+1]);
            }
        }
    }
    // 어느 한쪽 더미의 카드가 모두 소진될 때(i == n || j == n) 게임이 종료
    int ret = 0;
    for(int k = 0; k <= n; k++) {
        ret = max({ret, dp[n][k], dp[k][n]});   // A가 카드를 다 쓴 경우, B가 카드를 다 쓴 경우
    }
    cout << ret << '\n';
    return 0;
}
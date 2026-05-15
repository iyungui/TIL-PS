#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int dp[104][104], A[104][104];
int min_diff = INF;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // 최솟값이 k 라고 가정(고정)
    for(int k = 1; k <= 100; k++) {
        // 만약 시작점의 값이 k보다 작다면, continue
        if(A[0][0] < k) continue;

        // 시작점에서 i,j에 도달하기 위해 지나치는 칸들 중 최솟값이 k일 때, 경로의 최댓값
        memset(dp, INF, sizeof(dp));
        dp[0][0] = A[0][0];

        for(int i = 1; i < n; i++) {
            if(A[i][0] < k) dp[i][0] = INF;
            else dp[i][0] = max(dp[i-1][0], A[i][0]);
        }
        for(int j = 1; j < n; j++) {
            if(A[0][j] < k) dp[0][j] = INF;
            else dp[0][j] = max(dp[0][j-1], A[0][j]);
        }

        // 시작점에서 도착점까지 가면서 겪게 되는 '최댓값'을 최대한 작게 유지하면서 이동
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < n; j++) {
                // 만약 (i,j)칸이 최솟값 k 보다 작은 칸 이라면, 갈 수 없으므로
                if(A[i][j] < k) {
                    dp[i][j] = INF;
                }
                else {
                    dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), A[i][j]);
                }
            }
        }

        if(dp[n-1][n-1] != INF) min_diff = min(min_diff, dp[n-1][n-1] - k);
    }
    cout << min_diff << '\n';
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int TC;

int N, L;   // 재료의 수, 제한 칼로리

int T[24], K[24];   // 맛 점수 T, 칼로리 K
int ret;
int dp[21][10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> TC;
    for(int t = 0; t < TC; t++) {
        cin >> N >> L;
        memset(T, 0, sizeof(T));
        memset(K, 0, sizeof(K));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= N; i++) cin >> T[i] >> K[i];
        
        for(int i = 1; i <= N; i++) {
            for(int w = 0; w <= L; w++) {
                dp[i][w] = dp[i-1][w];
                if(w >= K[i]) {
                    dp[i][w] = max(dp[i-1][w], dp[i-1][w - K[i]] + T[i]);
                }
            }
        }

        cout << "#" << t + 1 << " " << dp[N][L] << '\n'; 
    }
    return 0;
}
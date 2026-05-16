#include <bits/stdc++.h>
using namespace std;

// 막대기를 적절히 나누어, 최대 수익을 구하라
/*
len[4]

중복 ok.
지금까지 선택한 길이의 합이 같다면, 수익이 큰 게 좋다

dp[104] = dp[i]: 길이가 i인 막대기의 최대 수익
dp[0] = 0
나머지 dp = 주어지는 수익 값
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
        dp[i] = max(dp[i], dp[i-j] + price[j])
    }
}
길이 4이고, 1만큼 잘랐으면,
dp[4-1] = dp[3] 에 대한 이익 + price[1]
*/
int main() {
    int n; cin >> n;
    vector<int> price(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> price[i];

    vector<int> dp(n+1, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i-j] + price[j]);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
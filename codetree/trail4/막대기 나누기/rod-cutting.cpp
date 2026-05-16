#include <bits/stdc++.h>
using namespace std;

int price[104], dp[104];

// 현재 막대기의 길이(n)
int solve(int n) {
    // 길이가 0 이하인 막대기의 수익은 0
    if(n <= 0) return 0;

    int &ret = dp[n];
    if(~ret) return ret;

    for(int i = 1; i <= n; i++) {
        ret = max(ret, price[i] + solve(n-i));
    }

    return ret;
}

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> price[i];

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int ret = solve(n);
    cout << ret << '\n';
    return 0;
}
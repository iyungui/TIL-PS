#include <bits/stdc++.h>
using namespace std;
// 중복ok
int dp[1004];   // dp[i]: i를 1, 2, 5의 합으로 나타내는 방법의 수
int numbers[] = {1, 2, 5};
const int mod = 10007;
int n;
int main() {
    cin >> n;
    dp[0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int num : numbers) {
            if(i >= num) dp[i] = (dp[i] + dp[i - num]) % mod;
        }
    }
    cout << dp[n] % mod << '\n';
    return 0;
}
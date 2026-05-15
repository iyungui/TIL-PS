#include <bits/stdc++.h>
using namespace std;

int n;
int A[1004], dp[1004];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] == -1) continue;
        for(int j = 1; j <= A[i]; j++) {
            if(i+j < n) {
                dp[i+j] = max(dp[i+j], dp[i]+1);
            }
        }
    }
    cout << *max_element(dp, dp + n);
    return 0;
}
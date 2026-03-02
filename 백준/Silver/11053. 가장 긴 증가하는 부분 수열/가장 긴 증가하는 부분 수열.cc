#include<bits/stdc++.h>
using namespace std;

int n;
int a[1004], dp[1004], ret;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    fill(dp, dp + n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp, dp + n) << '\n';
    return 0;
}
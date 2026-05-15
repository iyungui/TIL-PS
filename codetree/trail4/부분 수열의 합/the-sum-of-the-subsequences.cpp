#include <bits/stdc++.h>
using namespace std;

int dp[10004];  // 합이 i가되는 부분수열이 있으면 1, 없으면 -1
int main() {
    int n, m; cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;


    // 중복 사용 x
    for(int i = 0; i < n; i++) {
        int x = A[i];
        for(int j = m; j >= x; j--) {
            if(dp[j-x] == -1) continue;
            dp[j] = 1;
        }
    }

    if(dp[m] == 1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
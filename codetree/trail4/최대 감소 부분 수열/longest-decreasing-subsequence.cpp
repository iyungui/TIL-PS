#include <bits/stdc++.h>
using namespace std;

int n;
// i번째 원소까지 고려했을 때 가장 긴 감소부분 수열의 길이
int dp[1004], ret, A[1004];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(A[i] < A[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ret = max(ret, dp[i]);
    }
    cout << ret << '\n';
    return 0;
}
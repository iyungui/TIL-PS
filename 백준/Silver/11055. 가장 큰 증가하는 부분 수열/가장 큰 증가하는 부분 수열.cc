#include<bits/stdc++.h>

using namespace std;

int N;
int A[1004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> dp(N+1, 0);
    
    for(int i = 0; i < N; i++) {
        dp[i] = A[i];
        for(int j = 0; j < i; j++) {
            if(A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
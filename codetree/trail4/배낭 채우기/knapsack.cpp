#include <bits/stdc++.h>
using namespace std;

// 중복선택 x
// dp[i] = 무게 합이 i인 보석들의 가치합 중 최댓값
int n, m;
const int INF = -1e9;
int main() {
    cin >> n >> m;
    vector<pair<int, int>> v(n);    // 무게, 가치
    vector<int> dp(m+1, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for(int i = 0; i < n; i++) {
        auto [w, val] = v[i];
        for(int j = m; j >= w; j--) {
            if(j-w < 0) continue;
            if(dp[j-w] == INF) continue;
            dp[j] = max(dp[j], dp[j-w] + val);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
// 무게가 같다면 가치가 큰 것이 좋은 것
// dp[i] = 무게합이 i일 때 최대가치합
// dp[0] = 0, 나머지는 -1
// 중복 보석 선택 가능.(앞에서부터 채우기)
int main() {
    cin >> n >> m;
    // (무게, 가치)
    vector<pair<int, int>> v(n);
    vector<int> dp(m+1, -1);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            auto [w, val] = v[j];

            if(i - w < 0) continue;
            if(dp[i-w] == -1) continue;
            dp[i] = max(dp[i], dp[i-w] + val);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
/*
0 1 2 3 4 5 6 7

*/
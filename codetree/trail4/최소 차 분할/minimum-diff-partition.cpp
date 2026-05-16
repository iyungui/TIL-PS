#include <bits/stdc++.h>
using namespace std;

// i번째 수까지 고려, 합이 j인 부분집합이 존재한다면 1, 아니라면 0
// (case1) i번째 수를 포함하여 합이 j인 경우
// -> i-1번째 수까지 고려했을때, 합이 j-nums[i] 였어야 함.
//  (단 j-nums[i] >= 0 이어야 하고, 이전상태도 가능했어야함(dp[i-1][j-nums[i]])

// (case2) i번째 수를 포함하지 않고 합이 j인 경우
// -> i-1번째 수까지 고려했을때, 합이 j 였어야 함

// 점화식
// dp[i][j] = true (j-nums[i] >= 0 and dp[i-1][j-nums[i]] = true) or (dp[i-1][j] = true)

int main() {
    int n; cin >> n;
    vector<int> nums(n+1);
    int total = 0;  // 전체 집합의 합
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        total += nums[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(total+1, false));
    // 0번째 수까지 고려, 합이 0인 부분집합은 존재함
    dp[0][0] = true;

    // dp테이블 채우기
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < total; j++) {
            // (case1) i번째 수를 포함하여 합이 j인 경우
            if(j-nums[i] >= 0 && dp[i-1][j-nums[i]]) dp[i][j] = true;

            // (case2) i번째 수를 포함하지 않고 합이 j인 경우
            if(dp[i-1][j]) dp[i][j] = true;
        }
    } 

    // 테이블을 다 채우고,
    // dp[n][j] 가 true라면 (j는 1부터 total-1 까지) 
    // 그룹 A의 합은 j이고
    // 그룹 B의 합은 total - j 임.
    int min_diff = total;
    for(int A = 1; A < total; A++) {
        if(dp[n][A]) {
            int B = total - A;
            min_diff = min(min_diff, abs(B-A));
        }
    }
    cout << min_diff << '\n';
    return 0;
}
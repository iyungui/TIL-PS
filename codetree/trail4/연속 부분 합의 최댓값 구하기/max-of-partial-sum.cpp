#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    vector<int> nums(n+1);
    for(int i = 1; i <= n; i++) cin >> nums[i];

    // dp[i] = i번째 원소를 마지막으로 하는 연속한 부분수열에 속한 원소들의 합의 최댓값
    vector<int> dp(n+1, -1e9);
    // 초기값
    dp[0] = 0;
    dp[1] = nums[1];

    // dp테이블 채우기
    // i번째 원소를 시작으로 하는 연속부분수열 nums[i]
    // i번째 원소를 마지막으로 하는 연속부분수열 중 최대값 dp[i-1] + nums[i]
    for(int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
    }
    cout << *max_element(dp.begin() + 1, dp.end()) << '\n'; // dp[0]은 제외
    return 0;
}
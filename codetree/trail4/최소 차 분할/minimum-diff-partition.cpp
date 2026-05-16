#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int total = 0;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        total += nums[i];
    }

    // 전체 합의 절반
    int target = total / 2;
    // 합이 j가 되는 부분 집합이 존재하는가?
    vector<bool> dp(target+1, false);
    dp[0] = true;

    // 0-1 배낭 방식(중복x)으로 dp 테이블 채우기
    for(int i = 0; i < n; i++) {
        int x = nums[i];
        for(int j = target; j >= x; j--) {
            // j-x를 만들 수 있는 부분집합이 있다면
            // j도 만들 수 있다
            if(dp[j - x]) {
                dp[j] = true;
            }
        }
    }
    int max_sum_A = 0;
    for(int i = target; i >= 0; i--) {
        if(dp[i]) {
            max_sum_A = i;
            break;
        }
    }
    int max_sum_B = total - max_sum_A;

    cout << max_sum_B - max_sum_A << '\n';
    return 0;
}

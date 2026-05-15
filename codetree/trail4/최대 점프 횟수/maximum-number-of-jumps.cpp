#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // i번째 위치에 도달하기 위한 최대 점프 횟수
    vector<int> dp(n, -1);
    dp[0] = 0;

    int max_jumps = 0;

    for(int i = 0; i < n; i++) {
        // 현재 위치에 도달할 수 없는 경우 건너뜀
        if(dp[i] == -1) continue;

        // 현재 위치에서 뛸 수 있는 모든 거리에 대해 탐색
        for(int j = 1; j <= arr[i]; j++) {
            // 배열의 범위를 벗어나지 않는지 확인
            if(i + j < n) {
                dp[i+j] = max(dp[i+j], dp[i] + 1);
            }
        }
    }

    // dp 배열 내에서 가장 큰 값이 가능한 최대 점프 횟수
    for(int i = 0; i < n; i++) {
        if(dp[i] > max_jumps) max_jumps = dp[i];
    }
    cout << max_jumps << '\n';
    return 0;
}
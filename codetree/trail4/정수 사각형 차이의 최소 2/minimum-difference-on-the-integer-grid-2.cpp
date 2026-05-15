#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n;
int A[104][104], dp[104][104];
int min_diff = INF;

void initialize() {
    // 최솟값을 구해야 하므로 최댓값부터!
    memset(dp, INF, sizeof(dp));
    // 시작점 초기값 설정
    dp[0][0] = A[0][0];

    // 최좌측 열의 초기값 설정
    for(int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], A[i][0]);
    }
    // 최상단 행 초기화
    for(int j = 1; j < n; j++) {
        dp[0][j] = max(dp[0][j-1], A[0][j]);
    }
}

int solve(int low) {
    // lower_bound 미만의 값은 사용할 수 없도록, 값 초기화
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] < low) A[i][j] = INF;
        }
    }
    
    // DP 초기값 설정
    initialize();

    // 탐색하는 위치의 위에 값과 좌측 값 중에 작은 값과
    // 해당 위치의 숫자 중에 최댓값 구하기
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), A[i][j]);
        }
    }

    return dp[n-1][n-1];
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // 최솟값을 lower_bound라고 가정했을 때
    // lower_bound 이상의 수들만 사용하여
    // 이동한다는 조건하에서
    // 최댓값을 최소로 만드는 DP 배열을 만들기
    for(int lower_bound = 1; lower_bound <= 100; lower_bound++) {
        int upper_bound = solve(lower_bound);

        // 다 진행했음에도 여전히 INF라면, 이동이 불가능하다는 뜻이므로 패스
        if(upper_bound == INF) continue;

        // 답 갱신
        min_diff = min(min_diff, upper_bound - lower_bound);
    }

    cout << min_diff << '\n';
    return 0;
}
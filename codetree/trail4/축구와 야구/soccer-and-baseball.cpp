#include <bits/stdc++.h>
using namespace std;
/*
dp[12][10]: dp[k][i][j] = k번째 학생까지 고려, 축구팀을 i명, 야구팀을 j명 선발했을때, 두 팀의 능력의 합 최대값
dp[k][i][j] = dp[k-1][i][j], dp[k-1][i-1][j] + A, dp[k-1][i][j-1] + B; // i번째 학생을 축구팀에 넣을지. 야구팀에 넣을지. 아니면 넣지 않을지.
*/
struct Info {
    int s, b;
};
int dp[1004][12][10];
int main() {
    int n; cin >> n;
    vector<Info> infos(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> infos[i].s >> infos[i].b;
    }
    for(int k = 0; k <= n; k++) {
        for(int i = 0; i <= 11; i++) {
            for(int j = 0; j <= 9; j++) {
                dp[k][i][j] = -1e9; // 모든 상태를 불가능한 상태로 초기화
            }
        }
    }
    dp[0][0][0] = 0;    // 시작점 설정

    for(int k = 1; k <= n; k++) {
        for(int i = 0; i <= 11; i++) {
            for(int j = 0; j <= 9; j++) {
                // k번째 학생을 아무 팀에도 넣지 않는 경우
                dp[k][i][j] = dp[k-1][i][j];
                // 축구팀에 넣는 경우
                if(i > 0) dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-1][j] + infos[k].s);
                // 야구팀
                if(j > 0) dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j-1] + infos[k].b);
            }
        }
    }

    cout << dp[n][11][9] << '\n';
    return 0;
}
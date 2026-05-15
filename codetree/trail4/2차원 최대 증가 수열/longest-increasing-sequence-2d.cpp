#include <bits/stdc++.h>
using namespace std;

int n, m;
// 오름차순
// d[i][j] = d[i-a][j-b] + 1 (a와 b모두 1이상)
// dp 배열 처음에는 -1로 초기화
// dp[0][0] = 1
/*
for i : 0 -> n
    for j : 0 -> n
        d[i][j] == -1 이면 continue
        for k : 1 -> n
            for l : 1 -> n
                if(i+k < n && A[i+k][j+l] > A[i][j])
*/
int A[54][54];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = 1;
    int ret = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dp[i][j] == -1) continue;
            for(int D = 1; D < n; D++) {
                for(int R = 1; R < m; R++) {
                    if(i+D < n && j+R < m && A[i+D][j+R] > A[i][j]) {
                        dp[i+D][j+R] = max(dp[i+D][j+R], dp[i][j] + 1);
                    }
                }
            }
            ret = max(ret, dp[i][j]);
        }

    }
    cout << ret << '\n';
    return 0;
}
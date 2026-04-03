#include<bits/stdc++.h>

using namespace std;

int n;
// d[i][j][k] = 파이프 한쪽 끝이 i,j이고 방향이 k인 상태까지 이동시키는 방법의 수
int d[20][20][3];
int b[20][20];  // 1: 벽
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }
    d[1][2][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= n; j++) {
            if(i == 1 && j == 2) continue;

            // 가로
            if(b[i][j] == 0) d[i][j][0] = d[i][j-1][0] + d[i][j-1][2];
            // 세로
            if(b[i][j] == 0) d[i][j][1] = d[i-1][j][1] + d[i-1][j][2];
            // 대각선
            if(b[i][j] == 0 && b[i-1][j] == 0 && b[i][j-1] == 0) {
                d[i][j][2] = d[i-1][j-1][0] + d[i-1][j-1][1] + d[i-1][j-1][2];
            }
        }
    }

    cout << d[n][n][0] + d[n][n][1] + d[n][n][2] << '\n';
    return 0;
}
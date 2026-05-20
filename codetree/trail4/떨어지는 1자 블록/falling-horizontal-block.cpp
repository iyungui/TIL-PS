#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[104][104];
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    k--;

    bool flag = 0;  // i번째 행에서 부딪혔는지 여부

    for(int i = 1; i < n; i++) {
        for(int j = k; j < k+m; j++) {
            if(board[i][j] == 1) {  // i번째 행에서 부딪혔다면, i-1번 행에 올리면됨.
                flag = 1;
                break;
            }
        }

        if(flag) {
            for(int j = k; j < k+m; j++) {
                board[i-1][j] = 1;
            }
            break;
        }
    }
    if(!flag) {
        for(int j = k; j < k+m; j++) board[n-1][j] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
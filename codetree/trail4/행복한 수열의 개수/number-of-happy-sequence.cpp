#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[104][104];

bool isHappy(int num, bool flag) {
    int cnt = 1;
    if(flag) {  // 행 체크
        int st = board[num][0];
        for(int j = 1; j < n; j++) {
            if(cnt == m) return 1;
            if(board[num][j] == st) cnt++;
            else {
                st = board[num][j];
                cnt = 1;
            }
        }
        return cnt == m;
    }
    // 열 체크
    int st = board[0][num];
    for(int i = 1; i < n; i++) {
        if(cnt == m) return 1;
        if(board[i][num] == st) cnt++;
        else {
            st = board[i][num];
            cnt = 1;
        }
    }
    return cnt == m;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(isHappy(i, 0)) cnt++;
        if(isHappy(i, 1)) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
int m = 3;

// A가 이기면 1, 지면 0
int get_win(int a, int b) {
    // 주먹 > 가위
    if(a == 0 && b == 1) return 1;
    // 가위 > 보자기
    if(a == 1 && b == 2) return 1;
    // 보자기 > 주먹
    if(a == 2 && b == 0) return 1;
    return 0;
}

int main() {
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        // 주먹0, 가위1, 보자기2
        char c; cin >> c;
        if(c == 'H') b[i] = 0;
        else if(c == 'S') b[i] = 1;
        else b[i] = 2;
    }
    vector<vector<int>> L(n, vector<int>(m, 0));
    vector<vector<int>> R(n, vector<int>(m, 0));
    
    for(int a = 0; a < 3; a++) {
        L[0][a] = get_win(a, b[0]);
    }
    for(int i = 1; i < n; i++) {
        for(int a = 0; a < 3; a++) {
            L[i][a] = L[i-1][a] + get_win(a, b[i]);
        }
    }

    for(int a = 0; a < 3; a++) {
        R[n-1][a] = get_win(a, b[n-1]);
    }
    for(int i = n-2; i >= 0; i--) {
        for(int a = 0; a < 3; a++) {
            R[i][a] = R[i+1][a] + get_win(a, b[i]);
        }
    }

    int max_wins = 0;

    // A가 모양을 바꾸지 않는경우(끝까지 한 가지 모양만 냄)
    for(int a = 0; a < 3; a++) {
        max_wins = max(max_wins, L[n-1][a]);
    }

    // i번째 판을 같은 것을 연속해서 내다가, i+1번째 판부터 모양을 바꿔서 내는 경우
    for(int i = 0; i < n-1; i++) {
        for(int c1 = 0; c1 < 3; c1++) { // 처음 내는 모양
            for(int c2 = 0; c2 < 3; c2++) { // 두번째 모양
                if(c1 == c2) continue;
                max_wins = max(max_wins, L[i][c1] + R[i+1][c2]);
            }
        }
    }
    cout << max_wins << '\n';
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int T, N, cnt;
int col[14];

bool check(int r, int c) {
    for(int i = 0; i < r; i++) {
        if(col[i] == c) return false;
        if(abs(col[i] - c) == abs(i - r)) return false;        
    }
    return true;
}

void backtrack(int r) {
    if(r == N) {
        cnt++; return;
    }
    for(int c = 0; c < N; c++) {
        if(check(r, c)) {
            col[r] = c;
            backtrack(r + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        cnt = 0;
        memset(col, -1, sizeof(col));
        backtrack(0);
        cout << "#" << t << " " << cnt << '\n';
    }
    return 0;
}
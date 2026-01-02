#include<bits/stdc++.h>

using namespace std;

int n, a[2200][2200];
int cnt[3]; // -1, 0, 1 로만 채워진 종이의 개수

bool check(int x, int y, int n) {
    for(int i = x; i < x + n; i++) {
        for(int j = y; j < y + n; j++) {
            if(a[i][j] != a[x][y]) return 0;
        }
    }
    return 1;
}

void solve(int x, int y, int z) {
    if(check(x, y, z)) {
        cnt[a[x][y] + 1]++;
        return; 
    }
    int n = z / 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            solve(x+(i*n), y+(j*n), n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    solve(0, 0, n);
    for(int i = 0; i < 3; i++) cout << cnt[i] << '\n';
    return 0;
}
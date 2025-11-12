#include<bits/stdc++.h>

using namespace std;

int T, n;
int a[14][14];

void pascal() {
    // j가 0인 부분은 모두 1로 만들기
    // j가 i인 부분은 모두 1로 만들기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][0] = 1;
            a[i][i] = 1;
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
}

void print(int t) {
    cout << "#" << t << '\n';

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 0) continue;
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n;
        memset(a, 0, sizeof(a));
        pascal();
        print(t);
    }
    return 0;
}
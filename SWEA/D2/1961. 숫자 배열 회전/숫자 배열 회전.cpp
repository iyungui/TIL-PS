#include<bits/stdc++.h>

using namespace std;

int T, n;
int a[10][10], r90[10][10], r180[10][10], r270[10][10]; 

void initialize() {
    memset(a, 0, sizeof(a));
    memset(r90, 0, sizeof(r90));
    memset(r180, 0, sizeof(r180));
    memset(r270, 0, sizeof(r270));

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void rotate() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            r90[j][n-1-i] = a[i][j];
            r180[n-1-i][n-1-j] = a[i][j];
            r270[n-1-j][i] = a[i][j];
        }
    }
}

void print(int t) {
    cout << "#" << t << "\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << r90[i][j];
        cout << " ";
        for(int j = 0; j < n; j++) cout << r180[i][j];
        cout << " ";
        for(int j = 0; j < n; j++) cout << r270[i][j];
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    for(int t = 1; t <= T; t++) {
        initialize();
        rotate();
        print(t);
    }
    return 0;
}
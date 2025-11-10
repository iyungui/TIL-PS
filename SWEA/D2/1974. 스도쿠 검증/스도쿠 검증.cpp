#include<bits/stdc++.h>
using namespace std;

int TC;
int a[10][10];
int row_visited[10];
int col_visited[10];
int visited[10];

bool check() {
    for(int i = 0; i < 9; i++) {
        memset(row_visited, 0, sizeof(row_visited));
        for(int j = 0; j < 9; j++) {
            if(row_visited[a[i][j]]) return 0;
            row_visited[a[i][j]] = 1;
        }
    }
    for(int i = 0; i < 9; i++) {
        memset(col_visited, 0, sizeof(col_visited));
        for(int j = 0; j < 9; j++) {
            if(col_visited[a[j][i]]) return 0;
            col_visited[a[j][i]] = 1;
        }
    }
    for(int i = 0; i < 9; i += 3) {
        for(int j = 0; j < 9; j += 3) {
            memset(visited, 0, sizeof(visited));
            for(int k = i; k < i + 3; k++) {
                for(int l = j; l < j + 3; l++) {
                    if(visited[a[k][l]]) return 0;
                    visited[a[k][l]] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
    cin >> TC;
    for(int t = 1; t <= TC; t++) {
        memset(a, 0, sizeof(a));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cin >> a[i][j];
            }
        }
        bool ret = check();
        cout << "#" << t << " " << ret << '\n';
    }
    return 0;
}
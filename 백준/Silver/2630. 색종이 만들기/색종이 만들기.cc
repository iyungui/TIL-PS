#include<bits/stdc++.h>
using namespace std;

int paper[130][130];
int n;
int cnt[2];

bool ok(int y, int x, int n) {
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if(paper[i][j] != paper[y][x]) return 0;
        }
    }
    return 1;
}

void go(int n, int y, int x) {
    if(n == 1 || ok(y,x,n)) {cnt[paper[y][x]]++; return;}
    int h = n/2;
    go(h,y,x);
    go(h,y+h,x);
    go(h,y,x+h);
    go(h,y+h,x+h);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> paper[i][j];
    }
    go(n, 0, 0);

    for(int i = 0; i < 2; i++) cout << cnt[i] << '\n';
    return 0;
}
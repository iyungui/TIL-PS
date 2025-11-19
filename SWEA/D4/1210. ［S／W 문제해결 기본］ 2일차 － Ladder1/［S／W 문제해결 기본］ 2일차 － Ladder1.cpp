#include<bits/stdc++.h>
using namespace std;

const int T = 10;
const int N = 100;
int a[N + 4][N + 4], tc, sy, sx;
int ret;
int go(int y, int x) {
    if(y == 0 && a[y][x]) {
        return x;
    }

    if(a[y-1][x]) y--;

    bool flag = false;
    while(x > 0 && a[y][x-1]) {
        x--;
        flag = true;
    }

    while(!flag && x < N - 1 && a[y][x+1]) x++;
    
    return go(y, x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for(int t = 1; t <= T; t++) {
        cin >> tc; ret = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> a[i][j];
                if(a[i][j] == 2) {
                    sy = i; sx = j;
                }
            }
        }

        while(sx > 0 && a[sy][sx - 1]) sx--;
        while(sx < N - 1 && a[sy][sx + 1]) sx++;
        cout << "#" << tc << " " << go(sy, sx) << '\n';
    }
    return 0;
}
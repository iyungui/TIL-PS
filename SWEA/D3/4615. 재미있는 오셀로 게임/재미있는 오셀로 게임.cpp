// 실수1: based Indexing -> 0-based Indexing 변환 까먹지 말기.
// 실수2: 다음 위치(ny, nx) 가  어디인지 "정확히". 추적하기. (ny, nx) 에 누적을 하고 있는지(ny += dy[i].) 아니면 (ny = y + dy[i]) 를 하고 있는지. 
// 항상 오버플로우. 언더플로우 조심.
#include<bits/stdc++.h>
using namespace std;

int T;
int n, m;
int y, x, color;
int a[10][10];

const int dy[] = {-1,-1,0,1,1,1,0,-1};
const int dx[] = {0,1,1,1,0,-1,-1,-1};

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}
 
void setting() {
    memset(a, 0, sizeof(a));
    int m = n / 2;
    a[m][m] = a[m-1][m-1] = 2;
    a[m-1][m] = a[m][m-1] = 1;
}

void go(int y, int x, int color) {
    int op = 3 - color;
    for(int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        vector<pair<int, int>> v;
        while(InRange(ny, nx) && a[ny][nx] == op) {
            v.push_back({ny, nx});
            ny += dy[i];
            nx += dx[i];
        }
        if(InRange(ny, nx) && a[ny][nx] == color && v.size()) {
            for(auto [py, px] : v) {
                a[py][px] = color;
            }
        }
    }
}

pair<int, int> count() {
    int B = 0, W = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 1) B++;
            if(a[i][j] == 2) W++;
        }
    }
    return {B, W};
}

int main() {

    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n >> m;

        setting();

        for(int i = 0; i < m; i++) {
            cin >> y >> x >> color;
            y--; x--;   // 1 based-indexing
            a[y][x] = color;
            go(y, x, color);
        }

        auto [B, W] = count();

        cout << "#" << t << " " << B << " " << W << '\n';
    }

    return 0;
}
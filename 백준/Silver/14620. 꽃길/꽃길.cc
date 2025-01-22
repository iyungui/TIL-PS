#include <bits/stdc++.h>

using namespace std;
const int INT = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int ret = INT, n, a[14][14], visited[14][14];

bool check(int y, int x) {
    if(visited[y][x]) return false;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) return false;
        if(visited[ny][nx]) return false;
    }
    return true;
}

int setFlower(int y, int x) {
    int sum = a[y][x];
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        sum += a[ny][nx];
        visited[ny][nx] = 1;
    }
    return sum;
}

void eraseFlower(int y, int x) {
    visited[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
    return;
}

void go(int cnt, int cost) {
    if(cnt == 3) {
        ret = min(ret, cost);
        return;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(check(i, j)) {
                go(cnt + 1, (cost + setFlower(i, j)));
                eraseFlower(i, j);
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    go(0, 0);
    cout << ret << '\n';
    return 0;
}



// 기존 완탐 패턴
//visited[ny][nx] = 1; // 하나의 영역만 방문 및 원복
//go()  // 어떤 재귀함수 호출.
//visited[ny][nx] = 0;


// setFlower 꽃을 심고. (여러개의 영역 방문처리.하고 비용도 계산하고)
// go() 어떤 재귀함수 호출.
// eraseFlower (여러개의 영역 원복)

// 꽃 세 개.를 피우기 위한 화단의 최소 비용을 구하는 재귀함수.
// go (int 꽃 몇개? cnt, 비용? int cost)
// if (cnt == 3) ret = min(ret, cost)

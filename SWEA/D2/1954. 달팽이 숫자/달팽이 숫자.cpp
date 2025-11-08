#include <iostream>
using namespace std;

int T;
int n;
int arr[10][10];

// 오.아.왼.위
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int y, x;

void go() {
    int dir = 0;
    int y = 0, x = 0;

    for(int i = 1; i <= n * n; i++) {
        arr[y][x] = i;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
            
        // 범위를 벗어난 경우, 이미 방문한 경우 => 회전
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] != 0) {
            dir = (dir + 1) % 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }

        y = ny;
        x = nx;
    }
}

void print(int t) {
    cout << "#" << t << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> n;
        
        fill(&arr[0][0], &arr[0][0] + 10 * 10, 0);
        go();
        
        print(i);
    }
}
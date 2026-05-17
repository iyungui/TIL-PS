#include <bits/stdc++.h>
using namespace std;

int n;
int grid[24][24];

int dy[] = {-1, -1, 1, 1};
int dx[] = {1, -1, -1, 1};
// 1번방향으로 이동한 횟수 = 3번방향으로 이동한 횟수
// 2번 .. = 4번 ..
// => 1번 방향으로 몇 칸, 2번 방향으로 몇 칸

// [a, b, a, b]
int get_sum(int y, int x, int a, int b) {
    int st = grid[y][x];
    int sum = st;

    for(int i = 0; i < 4; i++) {
        int cnt;
        if(i % 2 == 0) cnt = a;
        else cnt = b;

        int tmp = 0;
        while(tmp < cnt) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n) break;

            y = ny;
            x = nx;
            sum += grid[y][x];

            tmp++;
        }
        if(tmp < cnt) return 0;
    }

    return sum - st;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ret = 0;

    for(int i = 2; i < n; i++) {
        for(int j = 1; j < n; j++) {
            for(int a = 1; a < n - 1; a++) {
                for(int b = 1; b < n - 1; b++) {
                    ret = max(ret, get_sum(i, j, a, b));
                }
            }
        }
    }
    cout << ret << '\n';
    return 0;
}
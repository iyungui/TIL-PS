#include<bits/stdc++.h>

using namespace std;

int N, K, L;
int board[104][104];

// 상우하좌
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // 보드의 크기, 사과의 개수
    cin >> N >> K;

    while(K--) {
        int y, x; cin >> y >> x;
        board[y-1][x-1] = 1;    // y행 x열에 사과가 있음을 나타냄
    }

    // 방향 전환 횟수 L
    cin >> L;
    map<int, char> mp;

    while(L--) {
        int x; char c;
        cin >> x >> c;
        // x초 후에 방향 c로 전환
        mp[x] = c;
    }

    // 뱀의 초기 상태(머리, 방향)
    int y = 0, x = 0, d = 1;
    board[y][x] = 2;    // 뱀이 위치하면 2로 색칠

    deque<pair<int, int>> snake;
    snake.push_back({y, x});
    
    int cur_time = 0;

    while(1) {
        cur_time++;
        // 머리 이동 시도
        int ny = y + dy[d];
        int nx = x + dx[d];

        // 다음 칸이 벽이나 자기자신의 몸이라면 게임 종료
        if(ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == 2) break;

        // 다음 칸이 사과가 아닌 경우
        if(board[ny][nx] != 1) {
            // 꼬리를 덱에서 꺼내고 해당 칸 지우기
            auto tail = snake.front(); snake.pop_front();
            board[tail.first][tail.second] = 0;
        }

        // 뱀으로 표시
        board[ny][nx] = 2;
        snake.push_back({ny, nx});
        // 머리이동
        y = ny; x = nx;

        // 현재 시간에서 방향전환이 가능한 경우
        if(mp.count(cur_time)) {
            char dir = mp[cur_time];

            if(dir == 'D') d = (d+1) % 4;
            else d = (d+3) % 4;
        }
    }

    cout << cur_time << '\n';
    return 0;
}
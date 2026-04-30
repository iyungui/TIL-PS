#include <bits/stdc++.h>

using namespace std;

int n, m;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void fork(char target, vector<vector<char>>& board) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> to_remove;
    vector<vector<bool>> visited(n+2, vector<bool>(m+2, 0));
    
    // 좌측상단 시작
    visited[0][0] = 1;
    q.push({0, 0});
    
    while(!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n+2 || nx < 0 || nx >= m+2 || visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            // 빈 공간인 경우에만 q에 푸시
            if(board[ny][nx] == '.') {
                q.push({ny, nx});
            }
            // target이면 to_remove에 추가(q에는 추가하지않음으로써 다음탐색x)
            else if(board[ny][nx] == target) to_remove.push_back({ny, nx});
        }
    }
    
    // 한번에 제거
    for(auto& [y, x] : to_remove) {
        board[y][x] = '.';
    }
}

void crane(char target, vector<vector<char>>& board) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j] == target) board[i][j] = '.';
        }
    }
}

// 남은 컨테이너 수 카운트
int count(vector<vector<char>>& board) { 
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j] != '.') cnt++;
        }
    }
    return cnt;
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size(); m = storage[0].size();
    // 1. 여백 두고 초기화
    vector<vector<char>> board(n+2, vector<char>(m+2, '.'));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            board[i+1][j+1] = storage[i][j];
        }
    }
    
    // action
    for(const auto& r : requests) {
        // 지게차
        if((int)r.size() == 1) fork(r[0], board);
        else crane(r[0], board);
    }
    
    // count
    return count(board);
}
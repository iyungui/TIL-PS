#include <bits/stdc++.h>
using namespace std;

const int n = 4;
int board[5][5];
char dir;

// 바닥으로 밀기
void push_down() {
    // 숫자만 모으기 -> 짝지어 합치기 -> 바닥부터 배치
    // 모든 열에 대해
    for(int c = 0; c < n; c++) {
        vector<int> nums;

        // (1) 아래에서부터 위로 올라가면서 숫자만 모으기
        for(int r = n-1; r >= 0; r--) {
            if(board[r][c] != 0) nums.push_back(board[r][c]);
        }

        // 수집한 숫자들을 아래에서부터 두 개씩 비교하며 합치기
        vector<int> merged;
        int m = nums.size();
        for(int r = 0; r < m; r++) {
            // 다음 숫자가 존재하고, 현재 숫자와 같다면 merged에 푸시
            if(r+1 < m && nums[r] == nums[r+1]) {
                merged.push_back(nums[r] * 2);
                // 다음숫자는 이미 합쳐졌으므로 건너뛰기
                r++;
            }
            // 다르거나 마지막 숫자라면 그대로 유지
            else merged.push_back(nums[r]);
        }

        // merged를 board의 바닥부터 채우기. (나머지는 0으로 처리)
        int idx = 0;
        m = merged.size();
        for(int r = n-1; r >= 0; r--) {
            if(idx < m) board[r][c] = merged[idx++];
            else board[r][c] = 0;
        }
    }
}

void rotate() {
    int tmp[5][5];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp[j][n-1-i] = board[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = tmp[i][j];
        }
    }
    return;
}

void go(int d) {
    if(d == 'D') push_down();

    else if(d == 'R') {
        // 시계방향 -> push down -> 원복
        rotate();
        push_down();
        rotate(); rotate(); rotate();
    }

    else if(d == 'L') {
        rotate(); rotate(); rotate();
        push_down();
        rotate();
    }

    else if(d == 'U') {
        rotate(); rotate();
        push_down();
        rotate(); rotate();
    }
}

int main() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    cin >> dir;
    
    go(dir);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
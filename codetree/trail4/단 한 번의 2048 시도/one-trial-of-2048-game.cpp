#include <bits/stdc++.h>
using namespace std;

const int n = 4;
int board[5][5];

void push_down() {
    for(int j = 0; j < n; j++) {
        vector<int> nums;
        for(int i = n-1; i >= 0; i--) {
            if(board[i][j] != 0) nums.push_back(board[i][j]);
        }
        int m = nums.size();
        vector<int> merged;
        for(int i = 0; i < m; i++) {
            if(i+1 < m && nums[i] == nums[i+1]) {
                merged.push_back(nums[i] * 2);
                i++;
            }
            else merged.push_back(nums[i]);
        }
        int idx = 0;
        m = merged.size();
        for(int i = n-1; i >= 0; i--) {
            if(idx < m) board[i][j] = merged[idx++];
            else board[i][j] = 0;
        }
    }
    // 1. 숫자만 모으기
    // 2. 합치기
    // 3. 밑에서부터 배치
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
}

void go(char c) {
    if(c == 'L') {
        rotate(); rotate(); rotate();
        push_down();
        rotate();
    }
    else if(c == 'R') {
        rotate();
        push_down();
        rotate(); rotate(); rotate();
    }
    else if(c == 'U') {
        rotate(); rotate();
        push_down();
        rotate(); rotate();
    }
    else if(c == 'D') push_down();
}

void printResult() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    char d; cin >> d;

    go(d);

    printResult();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int count(int y, int x, vector<vector<int>>& arr) {
    int cnt = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(arr[y+i][x+j] == 1) cnt++;
        }
    }
    return cnt;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int ret = 0;
    for(int i = 0; i <= n-3; i++) {
        for(int j = 0; j <= n-3; j++) {
            ret = max(ret, count(i, j, arr));
        }
    }
    cout << ret << '\n';
    return 0;
}
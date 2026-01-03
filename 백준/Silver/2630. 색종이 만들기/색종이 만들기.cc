#include<bits/stdc++.h>

using namespace std;

int n;
int arr[130][130];
pair<int, int> ret;

bool ok(int sy, int sx, int size) {
    int start = arr[sy][sx];
    for(int i = sy; i < sy + size; i++) {
        for(int j = sx; j < sx + size; j++) {
            if(arr[i][j] != start) return false;
        }
    }
    return true;
}

void go(int i, int j, int size) {
    if (size == 1 || ok(i, j, size)) {
        arr[i][j] == 0 ? ret.first++ : ret.second++;
        return;
    }

    go(i, j, size / 2);
    go(i, j + size / 2, size / 2);
    go(i + size / 2, j, size / 2);
    go(i + size / 2, j + size / 2, size / 2);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    go(0, 0, n);

    cout << ret.first << '\n' << ret.second << '\n';
    return 0;
}
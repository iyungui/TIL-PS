#include<bits/stdc++.h>
using namespace std;

int N;
// k: r,g,b
int d[1004][3]; // d[i][k] = i번째 집을 k색으로 칠하는 비용의 최솟값
int r,g,b;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    cin >> r >> g >> b;
    d[1][0] = r;
    d[1][1] = g;
    d[1][2] = b;

    for(int i = 2; i <= N; i++) {
        cin >> r >> g >> b;
        d[i][0] = r + min(d[i-1][1], d[i-1][2]);
        d[i][1] = g + min(d[i-1][0], d[i-1][2]);
        d[i][2] = b + min(d[i-1][0], d[i-1][1]);
    }
    int mx = 1e9;
    for(int k = 0; k < 3; k++) {
        mx = min(mx, d[N][k]);
    }

    cout << mx << '\n';

    return 0;
}
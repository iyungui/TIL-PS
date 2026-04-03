#include<bits/stdc++.h>

using namespace std;

int tree[1001];
int d[1001][31];    // d[t][w] = t초에 w번 이동했을 때 최대 자두개수
int T, W;
int solve(int t, int w) {
    if(t > T) return 0;
    if(d[t][w] != -1) return d[t][w];
    int cur_pos = (w % 2 == 0) ? 0 : 1;
    int stay = solve(t + 1, w) + (cur_pos == tree[t]-1);

    int move = -1e9;
    if(w < W) move = solve(t + 1, w + 1) + ( (cur_pos^1) == tree[t] - 1);
    return d[t][w] = max(stay, move);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T >> W;
    memset(d, -1, sizeof(d));
    for(int i = 1; i <= T; i++) cin >> tree[i];

    // 0초에는 0번 이동, 0개 획득
    cout << solve(1, 0) << '\n';
    return 0;
}
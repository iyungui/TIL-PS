#include<bits/stdc++.h>
using namespace std;

int TC;
int N, L;
int T[1004], K[1004];
int ret;

void go(int idx, int score, int kcal) {
    if(idx == N) {
        ret = max(ret, score);
        return;
    }

    go(idx + 1, score, kcal);
    if(kcal + K[idx] <= L) go(idx + 1, score + T[idx], kcal + K[idx]);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
    cin >> TC;
    for(int t = 1; t <= TC; t++) {
        cin >> N >> L;
        memset(T, 0, sizeof(T));
        memset(K, 0, sizeof(K));

        for(int i = 0; i < N; i++) {
            cin >> T[i] >> K[i];
        }

        ret = 0;
        go(0, 0, 0);

        cout << "#" << t << " " << ret << '\n';
    }
    return 0;
}
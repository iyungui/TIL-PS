#include<bits/stdc++.h>

using namespace std;

int t;

int N, L;   // 재료의 수, 제한 칼로리

int T[24], K[24];   // 맛 점수 T, 칼로리 K
int ret;

void go(int idx, int score, int kcal) {
    if(idx == N) {
        ret = max(ret, score);
        return;
    }
    if (kcal + K[idx] <= L) go(idx + 1, score + T[idx], kcal + K[idx]);
    go(idx + 1, score, kcal);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> N >> L;
        memset(T, 0, sizeof(T));
        memset(K, 0, sizeof(K));

        for(int j = 0; j < N; j++) cin >> T[j] >> K[j];
        ret = 0;
        go(0, 0, 0);
        cout << "#" << i + 1 << " " << ret << '\n'; 
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int N, K;

// d[k]: 무게 합이 k일 때, 최대가치
int d[100004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int w, v; cin >> w >> v;
        // 뒤에서부터(K) 현재 물건의 무게(w)까지만 확인
        for(int j = K; j >= w; j--) {
            d[j] = max(d[j], v + d[j-w]);
        }
    }
    
    cout << d[K] << '\n';

    return 0;
}
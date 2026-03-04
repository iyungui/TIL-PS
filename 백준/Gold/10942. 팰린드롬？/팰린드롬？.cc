#include<bits/stdc++.h>
using namespace std;

int d[2004][2004], a[2004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        d[i][i] = 1;    // 길이가 1인 경우
        if(a[i-1] == a[i]) d[i-1][i] = 1;   // 길이가 2인 경우
    }

    // 길이가 3이상인 경우
    for(int gap = 2; gap < n; gap++) {
        for(int i = 1; i <= n - gap; i++) {
            int s = i;
            int e = i + gap;
            if(a[s] == a[e] && d[s+1][e-1]) d[s][e] = 1; 
        }
    }
    int m;
    cin >> m;
    while(m--) {
        int s, e;
        cin >> s >> e;
        cout << d[s][e] << '\n';
    }
}

// d[i][j] = i부터 j까지의 수가 팰린드롬이라면 1, 아니면 0
// j-i+1 == 1 일때, d[i][i] = 1
// j-i+1 == 2 일때, a[i] == a[i+1] 이라면 d[i][i+1] = 1
// 3이상이면, a[s] == a[e] 이고 d[s+1][e-1] 이 1이어야 d[s][e]가 1
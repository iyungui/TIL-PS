#include <bits/stdc++.h>
using namespace std;

// d[i][j] = i번째 원소까지 고려, 합이 j인 부분수열의 원소의 개수

// d[i] = 합이 i인 부분수열의 원소의 개수. (마지막원소는 i - A[j])
int n,m;
int d[10004];
int A[104];
const int INF = 0x3f3f3f3f;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> A[i];
    memset(d, INF, sizeof(d));
    d[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = m; j >= 0; j--) {
            if(j >= A[i]) {
                d[j] = min(d[j], d[j-A[i]] + 1);
            }
        }
    }
    if(d[m] == INF) cout << -1 << '\n';
    else cout << d[m] << '\n';
    return 0;
}
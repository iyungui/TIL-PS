#include<bits/stdc++.h>
using namespace std;

int T, N;
long long P[101];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    P[1] = 1; P[2] = 1; P[3] = 1;
    for(int i = 4; i <= 100; i++) {
        P[i] = P[i-2] + P[i-3];
    }
    cin >> T;
    while(T--) {
        cin >> N;
        cout << P[N] << '\n';
    }
    return 0;
}
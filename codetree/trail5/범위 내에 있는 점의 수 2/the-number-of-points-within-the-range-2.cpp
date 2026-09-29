#include <bits/stdc++.h>

using namespace std;

int N, Q;
const int MN = 1000000;
int psum[MN+1];

int main() {
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        psum[x] = 1;
    }

    for(int i = 1; i <= MN; i++) {
        psum[i] += psum[i-1];
    }

    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        
        cout << psum[b] - (a > 0 ? psum[a-1] : 0) << '\n';
    }

    // Please write your code here.

    return 0;
}

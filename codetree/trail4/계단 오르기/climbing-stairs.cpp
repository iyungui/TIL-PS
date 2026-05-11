#include <bits/stdc++.h>
using namespace std;

int d[1004], n;
const int mod = 10007;
int main() {
    // Please write your code here.
    cin >> n;
    d[1] = 0;
    d[2] = 1;
    d[3] = 1;
    d[4] = 1;
    for(int i = 5; i <= n; i++) {
        d[i] = (d[i-2] + d[i-3]) % mod;
    }
    cout << d[n] % mod << '\n';
    return 0;
}
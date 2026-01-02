#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c;

ll power(ll base, ll exp, ll mod) {
    if(exp == 1) return base % mod;

    ll val = power(base, exp / 2, mod);

    val = (val * val) % mod;

    if(exp % 2 == 1) return (val * base) % mod;
    return val;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b >> c;
    cout << power(a,b,c) << '\n';
    return 0;
}
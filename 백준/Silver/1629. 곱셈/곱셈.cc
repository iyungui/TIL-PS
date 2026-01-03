#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

ll go(ll a, ll b) {
    if(b == 1) return a % c;
    ll val = go(a, b / 2);
    val = (val * val) % c;
    if(b % 2 == 1) return (val * a) % c;
    return val;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b >> c;
    cout << go(a, b) << '\n';
    return 0;
}
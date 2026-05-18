#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll s; cin >> s;
    ll n = 1ll;

    ll low = 1;
    ll high = 2000000000ll;

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(mid * (mid + 1) / 2 <= s) {  // 1부터 mid까지의 합이 S이하인 경우
            low = mid + 1;  // 더 큰 mid로 시도
            n = max(n, mid);
        }
        // S 이상인 경우, 더 작은 mid로 시도
        else high = mid - 1;
    }
    cout << n << '\n';
    return 0;
}
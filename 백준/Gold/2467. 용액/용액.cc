#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll a[100004];
ll ret = 2e10;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0;
    int r = n-1;
    ll L = 0, R = 0;
    while(l < r) {
        ll cur = a[l] + a[r];
        
        // 현재 합의 절댓값이 이전에 저장한 최소합보다 작으면 갱신
        if(abs(cur) < ret) {
            ret = abs(cur);
            L = a[l]; R = a[r];
        }
        // 합이 0에 가까워지도록 포인터 이동
        if(cur > 0) {
            r--;
        }
        else if(cur < 0) {
            l++;
        }
        else if(cur == 0) break;
    }
    cout << L << " " << R << '\n';
    return 0;
}
// 양수 + 음수로 0에 가장 가까운 것
#include<bits/stdc++.h>

using namespace std;

int a[1004], d[1004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int ret = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        d[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) d[i] = max(d[i], d[j] + 1);
        }
        ret = max(ret, d[i]);
    }
    cout << ret << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int inc[1004], dc[1004], a[1004];
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        inc[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) inc[i] = max(inc[i], inc[j] + 1);
        }
    }
    for(int i = n-1; i >= 0; i--) {
        dc[i] = 1;
        for(int j = n-1; j > i; j--) {
            if(a[i] > a[j]) dc[i] = max(dc[i], dc[j] + 1);
        }
    }
    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret = max(ret, inc[i] + dc[i]);
    }
    cout << ret - 1 << '\n';
    return 0;
}
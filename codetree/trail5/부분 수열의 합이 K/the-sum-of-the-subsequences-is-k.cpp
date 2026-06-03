#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1004];
int psum[1004];
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    psum[1] = a[1];
    for(int i = 2; i <= n; i++) {
        psum[i] = psum[i-1] + a[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int sum = psum[j] - psum[i-1];
            if(sum == k) cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
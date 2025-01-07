#include <bits/stdc++.h>

using namespace std;

int n, k, psum[1000001], ret = INT_MIN, temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }
    
    for(int i = k; i <= n; i++) {
        ret = max(ret, psum[i] - psum[i - k]);
    }
    
    cout << ret;
    return 0;
}

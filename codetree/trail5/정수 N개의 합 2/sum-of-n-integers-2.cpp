#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[100004];
int psum[100004];
int ret = -1e9;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    // Please write your code here.
    for(int i = k; i <= n; i++) {
        ret = max(ret, psum[i] - psum[i-k]);
    }

    cout << ret << '\n';

    return 0;
}

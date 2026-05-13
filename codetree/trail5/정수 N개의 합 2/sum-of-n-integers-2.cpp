#include <iostream>
using namespace std;

int psum[100004];
int n, k;
int main() {
    cin >> n >> k;
    psum[0] = 0;
    for(int i = 1; i <= n; i++) {
        int num; cin >> num;
        psum[i] = psum[i-1] + num;
    }
    int ret = 0;
    for(int i = 1; i <= n-k; i++) {
        int tmp = psum[i+k] - psum[i];
        ret = max(ret, tmp);
    }
    cout << ret << '\n';
    return 0;
}
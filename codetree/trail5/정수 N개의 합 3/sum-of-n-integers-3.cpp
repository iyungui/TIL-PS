#include <iostream>
using namespace std;

int n, k;
int psum[504][504];
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int num; cin >> num;
            psum[i][j] = psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1] + num;
        }
    }

    int ret = 0;
    for(int i = k; i <= n; i++) {
        for(int j = k; j <= n; j++) {
            int tmp = psum[i][j] - psum[i-k][j] - psum[i][j-k] + psum[i-k][j-k];
            ret = max(ret, tmp);
        }
    }

    cout << ret << '\n';
    return 0;
}
#include <iostream>
using namespace std;

const int mod = 10007;
int n, d[1004];

int main() {
    // Please write your code here.
    cin >> n;
    d[1] = 1;
    d[2] = 2;
    // d[3] = 3;
    // 마지막을 1*2 두개로 채우느냐 d[i-2]
    // 2*1로 채우느냐 d[i-1]
    for(int i = 3; i <= n; i++) {
        d[i] = (d[i-1] + d[i-2]) % mod;
    }
    cout << d[n] % mod << '\n';
    return 0;
}
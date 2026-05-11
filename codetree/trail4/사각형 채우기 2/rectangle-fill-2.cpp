#include <iostream>
using namespace std;

int d[1004];
int n;
const int mod = 10007;
int main() {
    cin >> n;
    d[0] = 1;
    d[1] = 1;
    d[2] = 3;
    
    for(int i = 3; i <= n; i++) {
        d[i] = (d[i-1] + 2 * d[i-2]) % mod;
    }
    cout << d[n] % mod << '\n';
    return 0;   
}
#include <bits/stdc++.h>
using namespace std;

int n, a;
int main() {
    cin >> n >> a;
    int tmp = 1;
    while(tmp <= n) {
        if(tmp % a == 0) cout << 1 << '\n';
        else cout << 0 << '\n';
        tmp++;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
int d[50];
int main() {
    // Please write your code here.
    cin >> n;
    d[1] = 1;
    d[2] = 1;
    for(int i = 3; i <= n; i++) {
        d[i] = d[i-1]+d[i-2];
    }
    cout << d[n] << '\n';
    return 0;
}
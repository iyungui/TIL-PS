#include<bits/stdc++.h>
using namespace std;

void func(int a, int b, int n) {
    if(n == 1) {
        cout << a << " " << b << '\n';
        return;
    }
    func(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    func(6-a-b, b, n-1);
    return;
}

int k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> k;
    cout << (1<<k) - 1 << '\n';
    func(1, 3, k);
    return 0;
}
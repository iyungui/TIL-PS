#include <bits/stdc++.h>
using namespace std;

int x, n;
int a, b;
int sum;
int main() {
    cin >> x >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        sum += (a * b);
    }
    cout << ((sum == x) ? "Yes" : "No") << '\n';
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

string a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a > b) {
        cout << a << '\n';
    } else {
        cout << b << '\n';
    }
    return 0;
}
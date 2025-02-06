#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int i = 1;
    while(i <= n) {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << '\n';
        i++;
    }
    return 0;
}
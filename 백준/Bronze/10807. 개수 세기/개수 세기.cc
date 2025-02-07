#include <bits/stdc++.h>
using namespace std;

int n, a[104], v, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> v;
    for(int i = 0; i < n; i++) {
        if(a[i] == v) ret++;
    }
    cout << ret << '\n';
    return 0;
}
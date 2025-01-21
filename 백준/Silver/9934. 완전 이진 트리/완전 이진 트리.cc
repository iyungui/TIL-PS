#include <bits/stdc++.h>

using namespace std;
int n, a[1030];
vector<int> v[14];

void go(int s, int e, int level) {
    if(s > e) return;
    if(s == e) {
        v[level].push_back(a[s]);
        return;
    }
    int mid = (int)(s + e) / 2;
    v[level].push_back(a[mid]);
    go(s, mid - 1, level + 1);
    go(mid + 1, e, level + 1);
}
int main() {
    cin >> n;
    int _end = (int)pow(2, n) - 1;
    for(int i = 0; i < _end; i++) {
        cin >> a[i];
    }
    
    go(0, _end, 1);
    
    for(int i = 1; i <= n; i++) {
        for(int j : v[i]) {
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}
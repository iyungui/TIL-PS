#include <bits/stdc++.h>

using namespace std;

int n, m, a;
unordered_set<int> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        auto it = s.find(a);
        if(it != s.end()) cout << 1 << ' ';
        else cout << 0 << ' ';
    }

    // Please write your code here.
    

    return 0;
}

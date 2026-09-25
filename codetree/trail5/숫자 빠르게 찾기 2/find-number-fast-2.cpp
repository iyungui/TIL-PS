#include <bits/stdc++.h>

using namespace std;

int n, m, a, q;
set<int> st;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a;
        st.insert(a);
    }

    for (int i = 0; i < m; i++) {
        cin >> q;
        auto it = st.lower_bound(q);
        if(it == st.end()) cout << -1 << '\n';
        else cout << *it << '\n';
    }

    // Please write your code here.


    return 0;
}

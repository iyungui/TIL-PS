#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
unordered_set<int> st;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        st.insert(a);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b;
        auto it = st.find(b);
        if(it != st.end()) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    // Please write your code here.


    return 0;
}

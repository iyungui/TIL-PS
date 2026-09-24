#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int n, a;
unordered_set<int> st;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        st.insert(a);
    }
    cout << (int)st.size() << '\n';
    return 0;
}

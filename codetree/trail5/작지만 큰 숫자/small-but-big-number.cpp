#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> st;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        st.insert(num);
    }

    while(m--) {
        int num; cin >> num;
        auto it = st.upper_bound(num);
        if(it == st.begin()) cout << -1 << '\n';
        else {
            it--;   // // num보다 같거나 작은 수들 중 최댓값을 가리킴
            cout << *it << '\n';
            st.erase(it);
        }
    }
    return 0;
}
#include <iostream>
#include <set>

using namespace std;

int T;
int k;
char c;
int n;

set<int> st;

void go(char c, int n) {
    if(c == 'I') st.insert(n);
    else {
        if(st.rbegin() == st.rend()) return;

        if(n == 1) st.erase(*st.rbegin());
        else st.erase(*st.begin());
    }
}

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> c >> n;
            go(c, n);
        }
        if(st.rbegin() == st.rend()) cout << "EMPTY\n";
        else cout << *st.rbegin() << " " << *st.begin() << '\n';
        st.clear();
    }

    return 0;
}

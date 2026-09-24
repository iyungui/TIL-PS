#include <bits/stdc++.h>

using namespace std;

int n;
string com;
int x;
unordered_set<int> st;

void go(string& s, int x) {
    if(s == "add") st.insert(x);
    else if(s == "remove") st.erase(x);
    else {
        auto it = st.find(x);
        if(it == st.end()) cout << "false\n";
        else cout << "true\n";
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> com >> x;

        go(com, x);
    }

    return 0;
}

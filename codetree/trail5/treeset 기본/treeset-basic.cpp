#include <bits/stdc++.h>
using namespace std;

set<int> st;
int n;
int main() {
    cin >> n;
    while(n--) {
        string s; cin >> s;
        if(s == "add") {
            int x; cin >> x;
            st.insert(x);
        }
        else if(s == "remove") {
            int x; cin >> x;
            st.erase(x);
        }
        else if(s == "find") {
            int x; cin >> x;
            if(st.find(x) == st.end()) cout << "false" << '\n';
            else cout << "true" << '\n';
        }
        else if(s == "lower_bound") {
            int x; cin >> x;
            auto it = st.lower_bound(x);
            if(it == st.end()) cout << "None\n";
            else cout << *it << '\n';
        }
        else if(s == "upper_bound") {
            int x; cin >> x;
            auto it = st.upper_bound(x);
            if(it == st.end()) cout << "None\n";
            else cout << *it << '\n';
        }
        else if(s == "largest") {
            if(st.empty()) cout << "None\n";
            else cout << *st.rbegin() << '\n';
        }
        else {
            if(st.empty()) cout << "None\n";
            else cout << *st.begin() << '\n';
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int t;
string s;
int main() {
    cin >> t;
    
    while(t--) {
        
        // init
        cin >> s;
        stack<char> stk;
        
        for(int i = 0; i < s.size(); i++) {
            if(stk.size() && stk.top() == '(' && s[i] == ')') stk.pop();
            else stk.push(s[i]);
        }
        if(stk.empty()) cout << "YES\n";
        else cout << "NO\n";
        
    }
    return 0;
}
